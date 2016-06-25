/*
 *  InvestmentAccount.cpp
 *  AgileBook
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 *
 */

#include "InvestmentAccount.h"
#include "PayBillsContext.h"
#include "TransferMoneyContext.h"
#include <string>
#include <iostream>

using std::cout;
using std::endl;

InvestmentAccount::InvestmentAccount() : availableBalance_(Euro(0.00)) {}

Currency InvestmentAccount::availableBalance() const {
  cout << "InvestmentAccount::availableBalance returns "
            << availableBalance_ << endl;
  return availableBalance_;
}

void InvestmentAccount::increaseBalance(const Currency &c) {
  cout << "InvestmentAccount::increaseBalance(" << c << ")" << endl;
  availableBalance_ += c;
}

void InvestmentAccount::decreaseBalance(const Currency &c) {
  cout << "InvestmentAccount::decreaseBalance(" << c << ")" << endl;
  availableBalance_ -= c;
}

void InvestmentAccount::updateLog(const string &s, const MyTime &,
                                  const Currency &c) const {
  cout << "account: " << accountID() << " InvestmentAccount::updateLog(\""
            << s << "\", Time, " << c << ")" << endl;
}

