#include "Account.hpp"

Account::Account()
{
	_nbAccounts = 0;
	_totalAmount = 0;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;

	_displayTimestamp( void );

	_accountIndex = 0;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}
