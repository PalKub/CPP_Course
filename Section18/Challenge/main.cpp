#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

int main() {
    try {
        std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account>("Moe", -10.0);
        std::cout << *moes_account << std::endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    try {
        std::unique_ptr<Account> curlys_account = std::make_unique<Savings_Account>("Curly", 10.0, 3.0);
        std::cout << *curlys_account << std::endl;
        curlys_account->withdraw(20);
    }
    catch (const InsufficientFundsException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    std::cout << "Program completed succesfully" << std::endl;
    return 0;
}