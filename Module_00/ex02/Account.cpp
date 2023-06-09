/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:33:11 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/01 12:19:30 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ){	return (_nbAccounts); }
int	Account::getTotalAmount( void ){ return (_totalAmount); }
int	Account::getNbDeposits( void ){	return (_totalNbDeposits); }
int	Account::getNbWithdrawals( void ){ return (_totalNbWithdrawals); }
int	Account::checkAmount( void ) const{	return (_amount); }

void Account::_displayTimestamp()
{
	time_t timeNow;
	std::time(&timeNow);
	tm *timeLocal;
	timeLocal = localtime(&timeNow);
	std::cout 	<< "[" << timeLocal->tm_mday << "-" 
				<< timeLocal->tm_mon + 1 << "-" 
				<< timeLocal->tm_year + 1900 << "]";
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout 	<< " accounts:" << _nbAccounts << ";total:" << getTotalAmount();
	std::cout	<< ";deposits:" << _totalNbDeposits << ";withdrawals:" 
				<< _totalNbWithdrawals << std::endl;
	_totalAmount = 0;
}

void	Account::displayStatus( void) const{
	_displayTimestamp();
	std::cout 	<< " index:" << _accountIndex << ";amount:" << _amount 
				<< ";deposits:" << _nbDeposits << ";withdrawals:" 
				<< _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit  )
{
	_displayTimestamp();
	_nbDeposits += 1;
	std::cout 	<< " index:" << _accountIndex << ";p_amount:" << _amount;
	_amount = _amount + deposit;
	std::cout	<< ";deposit:" << deposit << ";amount:" << _amount
				<< ";nb_deposits:"<< _nbDeposits << std::endl;
	_totalNbDeposits++;
	_totalAmount += _amount;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if ( checkAmount() >= withdrawal)
	{
		_nbWithdrawals += 1;
		_totalNbWithdrawals++;
		std::cout 	<< " index:" << _accountIndex << ";p_amount:" << _amount;
		_amount = _amount - withdrawal;
		std::cout	<< ";withdrawal:" << withdrawal << ";amount:" << _amount
					<< ";nb_withdrawals:"<< _nbWithdrawals << std::endl;
		_totalAmount += _amount;
		return (true);
	}
	std::cout 	<< " index:" << _accountIndex << ";p_amount:" << _amount
			 	<< ";withdrawal:refused" << std::endl;
	_totalAmount += _amount;
	return (false);
	
}

Account::Account(int initial_deposit) : _accountIndex (_nbAccounts), _amount (initial_deposit), \
										_nbDeposits (0), _nbWithdrawals (0)
{
	this->_displayTimestamp();
	std::cout 	<< " index:" << this->getNbAccounts(); 
	std::cout	<< ";amount:" << initial_deposit << ";created" << std::endl;
	_totalAmount += initial_deposit;
	_nbAccounts++;
}

Account::~Account()
{
	this->_displayTimestamp();
	std::cout 	<< " index:" << _accountIndex;   
	std::cout	<< ";amount:" << _amount << ";closed" << std::endl;
	_nbAccounts--;
}
