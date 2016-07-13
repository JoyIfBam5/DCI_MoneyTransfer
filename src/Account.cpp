/*
 *  Account.cpp
 *  AgileBook
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 *
 */

#include "Account.h"
#include <sstream>

using namespace  std;

namespace
{
    int accountCounter = 0;
}

Account::Account() {
    acct_ = accountCounter++;
}


string Account::accountID() const {
    string retval;
    std::stringstream s(retval);
    s << acct_;
    return retval;
}