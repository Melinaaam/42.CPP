#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	Account::checkAmount();
	std::cout << "created;" << std::endl;
	_nbAccounts++;
	_totalAmount +=  _amount;
}

void Account::_displayTimestamp( void )
{
	time_t now = time(NULL);
	struct tm *localTime = localtime(&now);
    char buffer[20];
    
    strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
    
    std::cout << buffer;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amout:"<<_amount << ";";
	_nbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amout:"<<_amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits<< std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amout:"<<_amount << ";";
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return 0;
	}
	_nbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amout:"<<_amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals<< std::endl;
	return 1;
}
int		Account::checkAmount( void ) const
{
	std::cout << "amout:"<<_amount << ";";
	return(1);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	Account::checkAmount();
	std::cout << "deposit:" << _nbDeposits << ";";
	std::cout << "withdrawal:" << _nbWithdrawals<< std::endl;
}

int	Account::getNbAccounts( void )
{
	std::cout << " accounts:" << _nbAccounts << ";";
	return 1;
}
int	Account::getTotalAmount( void )
{
	std::cout << "total:" << _totalAmount << ";";
	return 1;
}
int	Account::getNbDeposits( void )
{
	std::cout << "deposits:" << _totalNbDeposits << ";";
	return 1;
}
int	Account::getNbWithdrawals( void )
{
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
	return 1;
}
void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	Account::getNbAccounts();
	Account::getTotalAmount();
	Account::getNbDeposits();
	Account::getNbWithdrawals();
}
Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	Account::checkAmount();
	std::cout << "closed" << std::endl;
}