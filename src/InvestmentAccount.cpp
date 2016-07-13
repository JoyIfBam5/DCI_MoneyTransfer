/*
 *  InvestmentAccount.cpp
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 */

#include "InvestmentAccount.h"
#include "PayBillsContext.h"
#include "TransferMoneyContext.h"
#include <string>
#include <iostream>

InvestmentAccount::InvestmentAccount() : availableBalance_(Euro(0.00)) {}

Currency InvestmentAccount::availableBalance() const {
    std::cout << "InvestmentAccount::availableBalance returns "
    << availableBalance_ << std::endl;
    return availableBalance_;
}

void InvestmentAccount::increaseBalance(const Currency &c) {
    std::cout << "InvestmentAccount::increaseBalance(" << c << ")" << std::endl;
    availableBalance_ += c;
}

void InvestmentAccount::decreaseBalance(const Currency &c) {
    std::cout << "InvestmentAccount::decreaseBalance(" << c << ")" << std::endl;
    availableBalance_ -= c;
}

void InvestmentAccount::updateLog(const std::string &s, const MyTime &,
                                  const Currency &c) const {
    std::cout << "account: " << accountID() << " InvestmentAccount::updateLog(\""
    << s << "\", Time, " << c << ")" << std::endl;
}