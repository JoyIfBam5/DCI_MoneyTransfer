/*
 *  Currency.h
 *  AgileBook
 *
 *  Created by James Coplien on 7/31/09.
 *  Copyright 2009 Gertrud & Cope. All rights reserved.
 *
 */


#ifndef _CURRENCY_H
#define _CURRENCY_H

#include <string>


class Currency;

class CurrencyBase 
{
friend class Currency;
public:
    CurrencyBase();
    virtual ~CurrencyBase() = default;

    virtual CurrencyBase &operator+=(const Currency& amount) = 0;
    virtual CurrencyBase &operator-=(const Currency& amount) = 0;
    virtual CurrencyBase &operator=(const Currency& amount) = 0;
    virtual std::string name() const = 0;
    virtual std::string sign() const = 0;
    virtual double amountInEuro() const = 0;
    virtual std::string asString() const = 0;
protected:
    unsigned referenceCount_;
};


class Currency 
{
public:
    Currency();
    Currency(const Currency& amount);
    virtual Currency& operator=(const Currency& amount);

    explicit Currency(CurrencyBase *derivedClassThis);
    virtual ~Currency();

    virtual Currency& operator+=(const Currency& amount);
    virtual Currency& operator-=(const Currency& amount);

    virtual std::string name() const;
    virtual std::string sign() const;
    virtual double amountInEuro() const;
    virtual std::string asString() const;

    friend 
    bool operator==(const Currency& x, const Currency& y);
    friend
    bool operator!=(const Currency& x, const Currency& y);
    friend
    bool operator<(const Currency& x, const Currency& y);
    friend
    bool operator>(const Currency& x, const Currency& y);
    friend
    bool operator<=(const Currency& x, const Currency& y);
    friend
    bool operator>=(const Currency& x, const Currency& y);

    friend
    std::ostream &operator<<(std::ostream& stream, const Currency& currency);

private:
    CurrencyBase *actualCurrency_;
};


class Euro: public CurrencyBase 
{
friend class Currency;
public:
    explicit Euro(double amount = 0.0);
    virtual ~Euro() = default;

    operator Currency();
    CurrencyBase *copy() const;
    Euro &operator+=(const Currency& amount) override;
    Euro &operator-=(const Currency& amount) override;
    Euro &operator=(const Currency& amount) override;
    std::string name() const override;
    std::string sign() const override;
    double amountInEuro() const override;
    std::string asString() const override;
private:
    double amount_;
};


#endif
