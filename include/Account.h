/*
 *  Account.h
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 *
 */

#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include <string>
#include "Currency.h"

class Account
{
public:
    Account();
    
    std::string accountID() const;
    
    virtual void increaseBalance(const Currency&) = 0;
    virtual void decreaseBalance(const Currency&) = 0;
    
private:
    int acct_;
};

#endif