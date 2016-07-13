//
//  MoneyPort.h
//  DCI Money Transfer
//
//  Created by James Coplien on 12/07/16.
//  Copyright © 2016 Gertrud & Cope. All rights reserved.
//

#ifndef MoneyPort_h
#define MoneyPort_h

#include "Context.h"

class MoneyPort {
    
// Common private utility functions

template <typename T>
auto creditors()
{
    return static_cast<T*>(Context::currentContext_)->creditors();
}

template <typename T, typename U>
auto self(U* u)
{
    return static_cast<T*>(u);
}

template <typename T>
auto recipient()
{
    auto result = dynamic_cast<T*>(Context::currentContext_);
    if (result)
        return result->destinationAccount();
    throw std::bad_cast(); // ("dynamic cast failed");
}
    
};



#endif /* MoneyPort_h */
