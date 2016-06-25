/*
 *  Context.h
 *  AgileBook
 *
 *  Created by James Coplien on 1/14/09.
 *  Copyright 2009 Gertrud & Cope. All rights reserved.
 *
 */

#ifndef _CONTEXT_H
#define _CONTEXT_H


class Context {
public:
    Context();
    virtual ~Context();
public:
    static Context *currentContext_;
private:
    Context *parentContext_;
};


#endif