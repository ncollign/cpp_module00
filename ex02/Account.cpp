#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) 
    : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;

    // Afficher la création du compte
    std::cout << "Account created: index=" << _accountIndex
              << ", amount=" << _amount << std::endl;
}

Account::~Account() {
    _totalAmount -= _amount;
    _nbAccounts--;

    // Afficher la destruction du compte
    std::cout << "Account closed: index=" << _accountIndex
              << ", amount=" << _amount << std::endl;
}

void Account::makeDeposit(int deposit) {
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    std::cout << "Deposit: index=" << _accountIndex
              << ", amount=" << _amount
              << ", deposits=" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    if (withdrawal > _amount) {
        std::cout << "Withdrawal refused: index=" << _accountIndex << std::endl;
        return false;
    }

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << "Withdrawal: index=" << _accountIndex
              << ", amount=" << _amount
              << ", withdrawals=" << _nbWithdrawals << std::endl;
    return true;
}

void Account::displayStatus() const {
    std::cout << "Account status: index=" << _accountIndex
              << ", amount=" << _amount
              << ", deposits=" << _nbDeposits
              << ", withdrawals=" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos() {
    std::cout << "Accounts: " << _nbAccounts
              << ", Total: " << _totalAmount
              << ", Deposits: " << _totalNbDeposits
              << ", Withdrawals: " << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp() {
    std::time_t now = std::time(nullptr);
    std::tm *local_time = std::localtime(&now);

    std::cout << "[" << (local_time->tm_year + 1900)
              << (local_time->tm_mon + 1)
              << local_time->tm_mday << "_"
              << local_time->tm_hour
              << local_time->tm_min
              << local_time->tm_sec << "] ";
}
