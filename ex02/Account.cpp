#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstddef>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) 
    : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {

	_displayTimestamp();
	_accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
	std::cout << "Account created: index=" << _accountIndex
              << ", amount=" << _amount << std::endl;
}

Account::~Account() {
    _displayTimestamp();
	_totalAmount -= _amount;
    _nbAccounts--;

    std::cout << "Account closed: index=" << _accountIndex
              << ", amount=" << _amount << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
	_amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

	std::cout << "Deposit: index=" << _accountIndex
              << ", amount=" << _amount
              << ", deposits=" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
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
    _displayTimestamp();
	std::cout << "Account status: index=" << _accountIndex
              << ", amount=" << _amount
              << ", deposits=" << _nbDeposits
              << ", withdrawals=" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
	std::cout << "Accounts: " << _nbAccounts
              << ", Total: " << _totalAmount
              << ", Deposits: " << _totalNbDeposits
              << ", Withdrawals: " << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp() {
    std::time_t now = std::time(NULL);
    std::tm *local_time = std::localtime(&now);

    std::cout << "[" << (local_time->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (local_time->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << local_time->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << local_time->tm_hour
              << std::setw(2) << std::setfill('0') << local_time->tm_min
              << std::setw(2) << std::setfill('0') << local_time->tm_sec << "] ";
}
