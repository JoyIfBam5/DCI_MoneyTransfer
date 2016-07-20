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

    template <typename T, typename U>
    auto SELF(U* u)
    {
        return static_cast<T*>(u);
    }

    template <typename T>
    auto RECIPIENT()
    {
        auto result = dynamic_cast<T*>(Context::currentContext_);
        if (result)
            return result->destinationAccount();
        throw std::bad_cast(); // ("dynamic cast failed");
    }
    
    template <typename T>
    auto AMOUNT()
    {
        auto result = dynamic_cast<T*>(Context::currentContext_);
        if (result)
            return result->amount();
        throw std::bad_cast(); // ("dynamic cast failed");
    }
    
};

#endif /* MoneyPort_h */
