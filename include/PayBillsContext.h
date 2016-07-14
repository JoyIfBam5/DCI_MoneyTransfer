/*
 *  PayBillsContext.h
 *
 *  Created by James Coplien on 9/13/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 */

#ifndef _PAYBILLSCONTEXT_H
#define _PAYBILLSCONTEXT_H

#include "TransferMoneyContext.h"
#include "Creditor.h"
#include <vector>

class Creditor;

class PayBillsContext: public Context
{
    template <typename T>
    auto CREDITORS()
    {
        return static_cast<T*>(Context::currentContext_)->creditors();
    }
    auto SOURCE_ACCOUNT()
    {
        return static_cast<T*>(Context::currentContext_)->sourceAccount();
    }
public:
    PayBillsContext();
    TransferMoneyContext::MoneySource *sourceAccount() const;
    std::vector<Creditor*> creditors() const;

    // Role behaviors
    void doit()  {
        // While object contexts are changing, we don't want to
        // have an open iterator on an external object. Make a
        // local copy.
        for (auto& credit : CREDITORS<PayBillsContext>()) {
            try {
                // Note that here we invoke another Use Case
                TransferMoneyContext transferTheFunds(credit->amountOwed(),
                                                      SOURCE_ACCOUNT<PayBillsContext>(),
                                                      credit->account());
                transferTheFunds.doit();
            } catch (const InsufficientFunds&) {
                throw;
            }
        }
    }
private:
    void lookupBindings();
    TransferMoneyContext::MoneySource *sourceAccount_;
    std::vector<Creditor *> creditors_;
};



#endif
