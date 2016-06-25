project(MoneyTransfer C CXX)

include_directories("${PROJECT_SOURCE_DIR}/..")

set(SOURCE
  Account.cpp
  CheckingAccount.cpp
  Context.cpp
  Creditor.cpp
  Currency.cpp
  Globals.cpp
  InvestmentAccount.cpp
  main.cpp
  MyExceptions.cpp
  MyTime.cpp
  PayBillsContext.cpp
  SavingsAccount.cpp
  TransferMoneyContext.cpp
)

set(HEADERS
  ../include/Account.h
  ../include/CheckingAccount.h
  ../include/Context.h
  ../include/Creditor.h
  ../include/CreditorAccount.h
  ../include/Currency.h
  ../include/Globals.h
  ../include/InvestmentAccount.h
  ../include/MoneySink.h
  ../include/MoneySource.h
  ../include/MyExceptions.h
  ../include/MyTime.h
  ../include/PayBillsContext.h
  ../include/SavingsAccount.h
  ../include/TransferMoneyContext.h
  ../include/TransferMoneySource.h
)

add_executable(MoneyTransfer ${SOURCE} ${HEADERS})

set_property(TARGET MoneyTransfer PROPERTY CXX_STANDARD 14)
set_property(TARGET MoneyTransfer PROPERTY CXX_STANDARD_REQUIRED ON)
