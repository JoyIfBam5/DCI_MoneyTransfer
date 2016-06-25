/*
 *  TransferMoneySource.h
 *  AgileBook
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 *
 */

#ifndef _TRANSFERFUNDS_H
#define _TRANSFERFUNDS_H

#include "Currency.h"
#include "MoneySource.h"
#include "MoneySink.h"
#include "Creditor.h"
#include "MyExceptions.h"
#include "Globals.h"
#include "PayBillsContext.h"
#include "TransferMoneyContext.h"
#include <string>


template <typename T, typename U>
auto self(U* u)
{
    return static_cast<T*>(u);
}

template <typename T>
auto recipient()
{
    auto result = dynamic_cast<T*>(Context::currentContext_);
    if (result)
        return result->destinationAccount();
    throw std::bad_cast(); // ("dynamic cast failed");
}

template <typename T>
auto creditors()
{
    return static_cast<T*>(Context::currentContext_)->creditors();
}

using namespace std;

template <class ConcreteDerived>
class TransferMoneySource: public MoneySource
{
public:
    TransferMoneySource() = default;
    virtual ~TransferMoneySource() = default;

    // Role behaviors
    void payBills() override {
        // While object contexts are changing, we don't want to
        // have an open iterator on an external object. Make a
        // local copy.
        auto all_creditors = creditors<PayBillsContext>();
        for (auto& credit : all_creditors) {
            try {
                // Note that here we invoke another Use Case
                TransferMoneyContext transferTheFunds(credit->amountOwed(),
                                                      self<ConcreteDerived>(this),
                                                      credit->account());
                transferTheFunds.doit();
            } catch (const InsufficientFunds&) {
                throw;
            }
        }
    }

    void transferTo(const Currency& amount) override {
        // This code is reviewable and
        // meaningfully testable with stubs!
        beginTransaction();

        if (self<ConcreteDerived>(this)->availableBalance() < amount) {
            endTransaction();
            throw InsufficientFunds();
        } else {
            self<ConcreteDerived>(this)->decreaseBalance(amount);
            recipient<TransferMoneyContext>()->increaseBalance(amount);
            self<ConcreteDerived>(this)->updateLog("Transfer Out", DateTime(), amount);
            recipient<TransferMoneyContext>()->updateLog("Transfer In", DateTime(), amount);
        }
        // gui->displayScreen(SUCCESS_DEPOSIT_SCREEN);
        endTransaction();
    }
};




template <class ConcreteDerived>
class TransferMoneySink: public MoneySink
{
public:
    TransferMoneySink() = default;
    virtual ~TransferMoneySink() = default;
    
    void transferFrom(const Currency& amount) {
        self<ConcreteDerived>(this)->increaseBalance(amount);
        self<ConcreteDerived>(this)->updateLog("Transfer in", DateTime(), amount);
    }
};



#endif