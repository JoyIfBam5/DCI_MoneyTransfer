/*
 *  InvestmentAccount.h
 *  AgileBook
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 *
 */

#ifndef _INVESTMENTACCOUNT_H
#define _INVESTMENTACCOUNT_H

#include "Account.h"
#include "Currency.h"
#include "TransferMoneySource.h"
#include "MyTime.h"

class XferMoneyContext;
class PayBillsContext;

class InvestmentAccount:
    public Account,
    public TransferMoneySource<InvestmentAccount> 
{
    friend class TransferMoneySource<InvestmentAccount>;

public:
    InvestmentAccount();
    Currency availableBalance() const;
    void increaseBalance(const Currency&);
    void decreaseBalance(const Currency&) override;
    void updateLog(const std::string&, const MyTime&, const Currency&) const override;
private:
    Currency availableBalance_;
};

#endif