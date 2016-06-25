/*
 *  MoneySink.h
 *  AgileBook
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 *
 */

#ifndef _MONEYSINK_H
#define _MONEYSINK_H


#include "MyTime.h"
#include "Currency.h"

#include <string>

class MoneySink 
{
public:
    virtual ~MoneySink() = default;
    virtual void increaseBalance(const Currency& amount) = 0;
    virtual void updateLog(const std::string&, const MyTime&, const Currency& amount) const = 0;

};


#endif