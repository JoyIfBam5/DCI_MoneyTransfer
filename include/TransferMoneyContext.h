/*
 *  TransferMoneyContext.h
 *  AgileBook
 *
 *  Created by James Coplien on 9/13/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 *
 */
 
// TransferMoneyContext knows how to find the objects for a given
// use case invocation; it associates those objects with
// the roles they play in a Use Case of this type; and it
// publishes those interface bindings for use by the
// method-ful roles that participate in the use case.
 
#ifndef _XFERMONEYCONTEXT_H
#define _XFERMONEYCONTEXT_H

#include "Account.h"
#include "Context.h"
#include "Currency.h"
class MoneySource;
class MoneySink;

class TransferMoneyContext: public Context
{
public:
    TransferMoneyContext();
    TransferMoneyContext(const Currency& amount, MoneySource *src, MoneySink *destination);
    void doit();
    MoneySource *sourceAccount() const;
    MoneySink *destinationAccount() const;
    Currency amount() const;
private:
    void lookupBindings();
    MoneySource *sourceAccount_;
    MoneySink *destinationAccount_;
    Currency amount_;
};
 
 
 
#endif

