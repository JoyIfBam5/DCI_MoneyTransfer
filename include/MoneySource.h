/*
 *  MoneySource.h
 *  AgileBook
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 *
 */

#ifndef _MONEYSOURCE_H
#define _MONEYSOURCE_H

#include <string>

class MyTime;
class Currency;

class MoneySource {
public:
    virtual ~MoneySource() = default;
    virtual void transferTo(const Currency& amount) = 0;
    virtual void decreaseBalance(const Currency& amount) = 0;
    virtual void payBills() = 0;
    virtual void updateLog(const std::string&, const MyTime&, const Currency& amount) const = 0;
};

#endif