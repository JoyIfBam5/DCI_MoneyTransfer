/*
 *  TransferMoneyContext.h
 *
 *  Created by James Coplien on 9/13/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
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
#include "MyExceptions.h"
#include "Globals.h"
#include "MoneyPort.h"
#include <string>


class MyTime;

class TransferMoneyContext: public Context
{
public:
    // Roles
    
    class MoneySource: public MoneyPort, public Account
    {
    public:
        virtual ~MoneySource() = default;
        virtual void transferTo() = 0;
        virtual void decreaseBalance(const Currency&) = 0;
        virtual void updateLog(const std::string&, const MyTime&, const Currency& amount) const = 0;
    };

    template <class RolePlayer>
    class TransferMoneySource: public MoneySource
    {
    public:
        TransferMoneySource() = default;
        virtual ~TransferMoneySource() = default;
        virtual void transferTo() override {
            // This code is reviewable and
            // meaningfully testable with stubs!
            beginTransaction();
            
            if (SELF<RolePlayer>(this)->availableBalance() < AMOUNT<TransferMoneyContext>()) {
                endTransaction();
                throw InsufficientFunds();
            } else {
                SELF<RolePlayer>(this)->decreaseBalance(AMOUNT<TransferMoneyContext>());
                RECIPIENT<TransferMoneyContext>()->increaseBalance(AMOUNT<TransferMoneyContext>());
                SELF<RolePlayer>(this)->updateLog("Transfer Out", DateTime(), AMOUNT<TransferMoneyContext>());
                RECIPIENT<TransferMoneyContext>()->updateLog("Transfer In", DateTime(), AMOUNT<TransferMoneyContext>());
            }
            // gui->displayScreen(SUCCESS_DEPOSIT_SCREEN);
            endTransaction();
        }
    };
    
    class MoneySink: public MoneyPort
    {
    public:
        virtual ~MoneySink() = default;
        virtual void increaseBalance(const Currency& amount) = 0;
        virtual void updateLog(const std::string&, const MyTime&, const Currency& amount) const = 0;
    };
    
    template <class RolePlayer>
    class TransferMoneySink: public MoneySink
    {
    public:
        TransferMoneySink() = default;
        virtual ~TransferMoneySink() = default;
        
        virtual void transferFrom(const Currency& amount) {
            SELF<RolePlayer>(this)->increaseBalance(amount);
            SELF<RolePlayer>(this)->updateLog("Transfer in", DateTime(), amount);
        }
    };
public:
    TransferMoneyContext();
    TransferMoneyContext(const Currency& amount, MoneySource *src, MoneySink *destination);
    void doit();
    TransferMoneyContext::MoneySource *sourceAccount() const;
    TransferMoneyContext::MoneySink *destinationAccount() const;
    Currency amount() const;
private:
    void lookupBindings();
    MoneySource *sourceAccount_;
    MoneySink *destinationAccount_;
    Currency amount_;
};

#endif
