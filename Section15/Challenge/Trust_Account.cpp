#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{name, balance, int_rate}, withdraw_times_left{max_withdrawal_times} {
}

bool Trust_Account::deposit(double amount) {
    if(amount >= deposit_bonus_threshold)
        return Savings_Account::deposit(amount + deposit_bonus);
    else
        return  Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    if(withdraw_times_left > 0 && amount < (balance * withdraw_size_limit)) {
        --withdraw_times_left;
        return Savings_Account::withdraw(amount);
    } else
        return false;
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%, " << account.deposit_bonus << "$, " << account.deposit_bonus_threshold << "$, " << account.withdraw_times_left << ", " << account.withdraw_size_limit << "]";
    return os;
}