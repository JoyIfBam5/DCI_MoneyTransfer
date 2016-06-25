//
//  main.cpp
//  AgileBook
//
//  Created by James Coplien on 9/2/08.
//  Copyright Gertrud & Cope 2008. All rights reserved.
//

#include "TransferMoneyContext.h"
#include "PayBillsContext.h"
#include <memory>

int main() {
    auto aNewUseCase = std::make_unique<TransferMoneyContext>();
    aNewUseCase->doit();
    
    auto anotherNewUseCase = std::make_unique<PayBillsContext>();
    anotherNewUseCase->doit();
}