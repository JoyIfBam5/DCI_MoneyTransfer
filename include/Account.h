/*
 *  Account.h
 *  AgileBook
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 *
 */

#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include <string>

class Account 
{
public:
    Account();

    std::string accountID() const;
    
private:
    int acct_;
};

#endif