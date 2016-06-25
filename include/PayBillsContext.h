/*
 *  PayBillsContext.h
 *  AgileBook
 *
 *  Created by James Coplien on 9/13/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 *
 */
 
 
#ifndef _PAYBILLSCONTEXT_H
#define _PAYBILLSCONTEXT_H

#include "Context.h"

#include <vector>

class MoneySource;
class Creditor;

class PayBillsContext: public Context
{
public:
    PayBillsContext();
    void doit();
    MoneySource *sourceAccount() const;
    std::vector<Creditor*> creditors() const;
private:
    void lookupBindings();
    MoneySource *sourceAccount_;
    std::vector<Creditor *> creditors_;
};
 
 
 
#endif

