/*
 *  TransferFundsExample.cpp
 *  AgileBook
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 *
 */

#include "SavingsAccount.h"
#include "PayBillsContext.h"
#include "TransferMoneyContext.h"

#include <iostream>
#include <cassert>

using namespace std;

SavingsAccount::SavingsAccount() 
    : availableBalance_(Euro(0.00)) {
  // no application code

  assert(availableBalance_ == Euro(0.0));
}

Currency SavingsAccount::availableBalance() const {
  cout << "SavingsAccount::availableBalance returns " << availableBalance_
            << std::endl;

  return availableBalance_;
}

void SavingsAccount::decreaseBalance(const Currency& c) {
  cout << "SavingsAccount::decreaseBalance(" << c << ")" << endl;
  assert(c > availableBalance_);
  availableBalance_ -= c;
  assert(availableBalance_ > Euro(0.0));
}

const unsigned MAX_BUFFER_SIZE = 256;

void SavingsAccount::updateLog(const string& logMessage, const MyTime& timeOfTransaction,
                               const Currency& amountForTransaction) const {
  assert(logMessage.size() > 0);
  assert(logMessage.size() < MAX_BUFFER_SIZE);
  assert(MyTime("00:00:00.00 1970/1/1") < timeOfTransaction);
  cout << "account: " << accountID() << " SavingsAccount::updateLog(\""
       << logMessage << "\", MyTime, " << amountForTransaction << ")"
       << endl;
}

void SavingsAccount::increaseBalance(const Currency& c) {
  cout << "SavingsAccount::increaseBalance(" << c << ")" << endl;
  availableBalance_ += c;
}
