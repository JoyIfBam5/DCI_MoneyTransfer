/*
 *  Context.cpp
 *  AgileBook
 *
 *  Created by James Coplien on 1/14/09.
 *  Copyright 2009 Gertrud & Cope. All rights reserved.
 *
 */

#include "Context.h"

Context *Context::currentContext_ = nullptr;

Context::Context() {
    parentContext_ = currentContext_;
    currentContext_ = this;
}

Context::~Context() {
    currentContext_ = parentContext_;
}
