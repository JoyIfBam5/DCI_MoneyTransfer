//
//  main.cpp
//  DCI Money Transfer
//
//  Created by James Coplien on 12/07/16.
//  Copyright © 2016 Gertrud & Cope. All rights reserved.
//

#include <iostream>

#include "TransferMoneyContext.h"
#include "PayBillsContext.h"
#include <memory>

int main() {
    // auto aNewUseCase = std::make_unique<TransferMoneyContext>();
    auto aNewUseCase = std::unique_ptr<TransferMoneyContext>(new TransferMoneyContext());
    aNewUseCase->doit();
    
    // auto anotherNewUseCase = std::make_unique<PayBillsContext>();
    auto anotherNewUseCase = std::unique_ptr<PayBillsContext>(new PayBillsContext());
    anotherNewUseCase->doit();
    return 0;
}
