/*
 *  Currency.h
 *  AgileBook
 *
 *  Created by James Coplien on 7/31/09.
 *  Copyright 2009 Gertrud & Cope. All rights reserved.
 *
 */

#include "Currency.h"

#include <sstream>

CurrencyBase::CurrencyBase() 
    : referenceCount_(1) 
{ }

Currency &Currency::operator+=(const Currency &amount) {
  *actualCurrency_ += amount;
  return *this;
}

Currency &Currency::operator-=(const Currency &amount) {
  *actualCurrency_ -= amount;
  return *this;
}

Currency &Currency::operator=(const Currency &amount) {
  amount.actualCurrency_->referenceCount_++;
  if (--actualCurrency_->referenceCount_ <= 0)
    delete actualCurrency_;
  actualCurrency_ = amount.actualCurrency_;
  return *this;
}


Currency::Currency(const Currency &amount) {
  (actualCurrency_ = amount.actualCurrency_)->referenceCount_++;
}

Currency::Currency() : actualCurrency_(new Euro) {}

Currency::~Currency() {
  if (--actualCurrency_->referenceCount_ <= 0)
    delete actualCurrency_;
}

std::string Currency::name() const
{
    return actualCurrency_->name();
}

std::string Currency::sign() const
{
    return actualCurrency_->sign();
}

double Currency::amountInEuro() const {
  return actualCurrency_->amountInEuro();
}

std::string Currency::asString() const {
  return actualCurrency_->asString();
}

std::ostream &operator<<(std::ostream &stream, const Currency &currency) {
  stream << currency.asString();
  return stream;
}

bool operator==(const Currency &x, const Currency &y) {
    return x.amountInEuro() == y.amountInEuro();
}

bool operator!=(const Currency &x, const Currency &y) {
    return !(x == y);
}

bool operator<(const Currency &x, const Currency &y) {
  return x.amountInEuro() < y.amountInEuro();
}

bool operator>(const Currency &x, const Currency &y) {
  return y < x ;
}

bool operator<=(const Currency &x, const Currency &y) {
  return !(y < x);
}

bool operator>=(const Currency &x, const Currency &y) {
  return !(x < y);
}

Currency::Currency(CurrencyBase *derivedClassThis)
    : actualCurrency_(derivedClassThis) 
{}


Euro::operator Currency()
{
    return Currency(this->copy());
}

CurrencyBase *Euro::copy() const
{
    return new Euro(amount_);
}

Euro &Euro::operator+=(const Currency &amount) {
  amount_ += amount.amountInEuro();
  return *this;
}

Euro &Euro::operator-=(const Currency &amount) {
  amount_ -= amount.amountInEuro();
  return *this;
}

Euro &Euro::operator=(const Currency &amount) {
  amount_ = amount.amountInEuro();
  return *this;
}

Euro::Euro(double amount) 
    : amount_(amount) 
{}

std::string Euro::name() const
{
    return "Euro";
}

std::string Euro::sign() const
{
    return "€";
}

double Euro::amountInEuro() const
{
    return amount_;
}

std::string Euro::asString() const {
  std::ostringstream stream;
  stream << amount_;
  return stream.str();
}

