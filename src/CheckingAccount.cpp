/*
 *  CheckingAccount.cpp
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 */

#include "CheckingAccount.h"
#include "PayBillsContext.h"
#include "Currency.h"
#include "TransferMoneyContext.h"
#include <iostream>

using namespace std;

CheckingAccount::CheckingAccount()
: availableBalance_(Euro(100.00))
{
}


Currency CheckingAccount::availableBalance() const
{
    cout << "CheckingAccount::availableBalance returns "
    << availableBalance_ << endl;
    
    return availableBalance_;
}

void CheckingAccount::decreaseBalance(const Currency& c) {
    cout << "CheckingAccount::decreaseBalance(" << c << ")" << endl;
    availableBalance_ -= c;
}

void CheckingAccount::updateLog(const string& message, const MyTime& t, const Currency& c) const {
    cout << "account: " << accountID() << " CheckingAccount::updateLog(\"" << message << "\", MyTime, " << c << ")"
    << endl;
}

void CheckingAccount::increaseBalance(const Currency& c) {
    cout << "CheckingAccount::increaseBalance(" << c << ")" << endl;
    availableBalance_ += c;
}