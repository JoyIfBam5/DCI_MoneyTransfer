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
    auto aNewUseCase = std::make_unique<TransferMoneyContext>();
    aNewUseCase->doit();

    auto anotherNewUseCase = std::make_unique<PayBillsContext>();
    anotherNewUseCase->doit();
    return 0;
}
