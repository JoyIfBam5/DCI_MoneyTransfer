/*
 *  Creditor.cpp
 *
 *  Created by James Coplien on 9/17/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 */

#include "Creditor.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

ElectricCompany::ElectricCompany()
{
    account_ = new CheckingAccount();
}

Currency ElectricCompany::amountOwed() const
{
    return Euro(15.0);
}

GasCompany::GasCompany()
{
    account_ = new SavingsAccount();
    account_->increaseBalance(Euro(500.00));	// start off with a balance of 500
}

Currency GasCompany::amountOwed() const
{
    return Euro(18.76);
}