/*
 *  PayBillsContext.cpp
 *
 *  Created by James Coplien on 9/17/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 */

#include "PayBillsContext.h"
#include "InvestmentAccount.h"
#include "SavingsAccount.h"
#include "Creditor.h"

PayBillsContext::PayBillsContext()
: Context() {
    lookupBindings();
}

void PayBillsContext::lookupBindings() {
    // These are somewhat arbitrary and for illustrative
    // purposes. The simulate a database lookup
    TransferMoneyContext::TransferMoneySource<InvestmentAccount> *investmentAccount = new InvestmentAccount;
    investmentAccount->increaseBalance(Euro(100.00)); // prime it with some money
    sourceAccount_ = investmentAccount;
    
    creditors_.push_back(new ElectricCompany);
    creditors_.push_back(new GasCompany);
}

TransferMoneyContext::MoneySource *PayBillsContext::sourceAccount() const {
    return sourceAccount_;
}

std::vector<Creditor *> PayBillsContext::creditors() const {
    return creditors_;
}
