#include "./Account.hpp"

#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_nbAccounts += 1;
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";ammount" << initial_deposit << ";created\n";
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount << ";closed\n";
}

// getting data
int	Account::getNbAccounts(void) {
	return(_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return(_totalAmount);
}

int Account::getNbDeposits(void) {
	return(_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
	return(_totalNbWithdrawals);
}

int	Account::checkAmount(void) const {
	return (_amount);
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;

	this-> _amount += deposit;
	this->_nbDeposits += 1;

	this->_totalAmount += deposit;
	this->_totalNbDeposits += 1;

	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

/**
 * @param int withdrawal ammount
 * @return 1 if withdrawal refused
*/
bool	Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;

	if (withdrawal <= _amount) {
		this->_amount -= withdrawal;
		this->_totalAmount-= withdrawal;

		this->_nbWithdrawals += 1;
		this->_totalNbWithdrawals += 1;

		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << _amount;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	} else {
		std::cout << ";withdrawal:refused\n";
		return (1);
	}
	//return (0);

	std::cout << ";withdrawal:" << withdrawal;
	return (0);
}

void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

/* std::string _displayTimestamp(void) {
	// Get the current time point
	auto now = std::chrono::system_clock::now();

	// Convert the time point to a time_t object
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

	// Format the time using std::put_time
	std::ostringstream oss;
	oss << std::put_time(std::localtime(&currentTime), "%Y%m%d_%H%M%S");

	return oss.str();
} */
