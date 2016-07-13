/*
 *  MyTime.cpp
 *  AgileBook
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 *
 */

#include "MyTime.h"

MyTime::MyTime(long long)
{ }

MyTime::MyTime(const std::string& timeAsString)
{ }

MyTime::~MyTime() { }

MyTime::MyTime(const MyTime &t) { }

MyTime &MyTime::operator=(const MyTime &t)
{
    return *this;
}

bool operator<(const MyTime &x, const MyTime &y)
{
    return true;
}