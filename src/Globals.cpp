/*
 *  Globals.cpp
 *  AgileBook
 *
 *  Created by James Coplien on 9/2/08.
 *  Copyright 2008 Gertrud & Cope. All rights reserved.
 *
 */

#include "Globals.h"


#include "MyTime.h"
#include <iostream>

void endTransaction() {
    std::cout << "::endTransaction()" << std::endl;
}

void beginTransaction() {
    std::cout << "::beginTransaction()" << std::endl;
}

MyTime DateTime() {
    return MyTime(0);
}