#include "Account.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	this->_nbAccounts = 0;
}

Account::~Account(void)
{

}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{

}
void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_nbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{}
// int		Account::checkAmount( void );
// void	Account::displayStatus( void );