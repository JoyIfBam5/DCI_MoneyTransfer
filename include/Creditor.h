/*
 *  Creditor.h
 *
 *  Created by James Coplien on 9/17/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 */

#ifndef _CREDITOR_H
#define _CREDITOR_H

#include "Currency.h"
#include "TransferMoneyContext.h"

class Creditor
{
public:
    virtual ~Creditor() = default;
    virtual TransferMoneyContext::MoneySink *account() { return account_; }
    virtual Currency amountOwed() const = 0;
protected:
    TransferMoneyContext::MoneySink *account_;
};


class ElectricCompany: public Creditor
{
public:
    ElectricCompany();
    virtual ~ElectricCompany() = default;
    Currency amountOwed() const override;
};


class GasCompany: public Creditor
{
public:
    GasCompany();
    virtual ~GasCompany() = default;
    Currency amountOwed() const override;
};

#endif