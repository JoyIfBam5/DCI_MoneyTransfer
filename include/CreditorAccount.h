/*
 *  CreditorAccount.h
 *
 *  Created by James Coplien on 9/17/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _CREDITORACCOUNT_H
#define _CREDITORACCOUNT_H

#include "MoneySink.h"

class CreditorAccount: public MoneySink
{
public:
    virtual ~CreditorAccount() = default;
    virtual void amountOwed() = 0;
};


#endif