/*
 *  InvestmentAccount.h
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 */

#ifndef _INVESTMENTACCOUNT_H
#define _INVESTMENTACCOUNT_H

#include "Account.h"
#include "Currency.h"
#include "TransferMoneyContext.h"
#include "MyTime.h"

class InvestmentAccount:
    public TransferMoneyContext::TransferMoneySource<InvestmentAccount>
{
public:
    InvestmentAccount();
    Currency availableBalance() const;
    void increaseBalance(const Currency&) override;
    void decreaseBalance(const Currency&) override;
    void updateLog(const std::string&, const MyTime&, const Currency&) const override;
private:
    Currency availableBalance_;
};

#endif
