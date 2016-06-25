/*
 *  Creditor.h
 *  AgileBook
 *
 *  Created by James Coplien on 9/17/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 *
 */

#ifndef _CREDITOR_H
#define _CREDITOR_H


#include "Currency.h"

class MoneySink;


class Creditor
{
public:
    virtual ~Creditor() = default;
    virtual MoneySink *account() const = 0;
    virtual Currency amountOwed() const = 0;
};



class ElectricCompany: public Creditor
{
public:
    ElectricCompany();
    virtual ~ElectricCompany() = default;

    MoneySink *account() const override;
    Currency amountOwed() const override;
private:
    MoneySink *account_;
};


class GasCompany: public Creditor
{
public:
    GasCompany();
    virtual ~GasCompany() = default;

    MoneySink *account() const override;
    Currency amountOwed() const override;
private:
    MoneySink *account_;
};

#endif
