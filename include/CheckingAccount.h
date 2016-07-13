/*
 *  CheckingAccount.h
 *
 *  Created by James Coplien on 9/17/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 */


#ifndef _CHECKINGACCOUNT_H
#define _CHECKINGACCOUNT_H

#include "Account.h"
#include "Currency.h"
#include "TransferMoneyContext.h"
#include "MyTime.h"

#include <string>

class CheckingAccount:
    public Account,
    public TransferMoneyContext::TransferMoneySink<CheckingAccount>
{
public:
    CheckingAccount();
    virtual ~CheckingAccount() = default;

    // These functions can be virtual if there are
    // specializations of CheckingAccount
    Currency availableBalance() const;
    void decreaseBalance(const Currency&) override;
    void increaseBalance(const Currency&) override;
    void updateLog(const std::string&, const MyTime&, const Currency&) const override;
    
private:
    Currency availableBalance_;
};

#endif