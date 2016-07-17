/*
 *  SavingsAccount.h
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 */

#ifndef _SAVINGSACCOUNT_H
#define _SAVINGSACCOUNT_H

#include "Account.h"
#include "TransferMoneyContext.h"
#include "MyTime.h"
#include <string>

class SavingsAccount:
    public Account,
    public TransferMoneyContext::TransferMoneySink<SavingsAccount> {
    friend class TransferMoneyContext::TransferMoneySink<SavingsAccount>;	// optional
public:
    SavingsAccount();
private:
    // These functions can be virtual if there are
    // specializations of SavingsAccount
    Currency availableBalance() const;
    void decreaseBalance(const Currency&) override;
    void increaseBalance(const Currency&) override;
    void updateLog(const std::string&, const MyTime&, const Currency&) const override;
private:
    Currency availableBalance_;
};

#endif