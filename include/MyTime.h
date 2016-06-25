/*
 *  Time.h
 *  AgileBook
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 *
 */

#ifndef _MYTIME_H
#define _MYTIME_H

#include <string>

class MyTime {
public:
    MyTime() = default;
    explicit MyTime(long long);
    explicit MyTime(const std::string& timeAsString);
    ~MyTime();
    MyTime(const MyTime& t);
    MyTime& operator=(const MyTime &t);

    friend
    bool operator<(const MyTime &x, const MyTime &y);
};


#endif