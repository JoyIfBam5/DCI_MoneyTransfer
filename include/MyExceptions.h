/*
 *  MyExceptions.h
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 *
 */

#ifndef _MYEXCEPTIONS_H
#define _MYEXCEPTIONS_H

#include <exception>

class InsufficientFunds : public std::exception
{
public:
    InsufficientFunds();
};


#endif