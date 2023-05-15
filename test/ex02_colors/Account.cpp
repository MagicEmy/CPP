/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:33:11 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/13 19:28:10 by emlicame         ###   ########.fr       */
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
	std::cout << " accounts:" << C_DMGNT << getNbAccounts(); 
	std::cout << C_RESET ";total:" << C_DMGNT << _totalAmount;
	std::cout << C_RESET << ";deposit:" << C_DMGNT << getNbDeposits();
	std::cout << C_RESET ";withdrawals:" << C_DMGNT << getNbWithdrawals(); 
	std::cout << C_RESET << std::endl;
}

void	Account::displayStatus( void) const{
	_displayTimestamp();
	std::cout 	<< " index:" << C_DRED << _accountIndex << C_RESET ";amount:" 
				<< C_DRED << _amount << C_RESET ";deposits:" 
				<< C_DRED << _nbDeposits << C_RESET ";withdrawals:" 
				<< C_DRED << _nbWithdrawals << C_RESET << std::endl;
}

void	Account::makeDeposit( int deposit  )
{
	_displayTimestamp();
	_nbDeposits = 1;
	_totalAmount = _amount + deposit;
	std::cout << " index:" << C_LVIOLET << _accountIndex; 
	std::cout << C_RESET ";p_amount:" << C_LVIOLET << _amount; 
	std::cout << C_RESET ";deposit:" << C_LVIOLET << deposit;
	std::cout << C_RESET ";amount:" << C_LVIOLET << _totalAmount;
	std::cout << C_RESET ";nb_deposits:"<< C_LVIOLET << _nbDeposits; 
	std::cout << C_RESET << std::endl;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	_nbDeposits = 1;
	_totalAmount = _amount - withdrawal;
	std::cout << " index:" << C_LVIOLET << _accountIndex; 
	std::cout << C_RESET ";p_amount:" << C_LVIOLET << _amount; 
	std::cout << C_RESET ";withdrawal:" << C_LVIOLET << withdrawal;
	std::cout << C_RESET ";amount:" << C_LVIOLET << _totalAmount;
	std::cout << C_RESET ";nb_withdrawals:"<< C_LVIOLET << _nbDeposits; 
	std::cout << C_RESET << std::endl;
	_totalNbWithdrawals++;
	return (true);
}

// Account::Account(int initial_deposit)
// {
// 	this->_displayTimestamp();
// 	_accountIndex = _nbAccounts;
// 	std::cout 	<< " index:" C_DBLUE << this->getNbAccounts(); 
// 	std::cout	<< C_RESET ";amount:" C_DBLUE
// 				<< initial_deposit << C_RESET ";created" << std::endl;
// 	_amount = initial_deposit;
// 	_nbDeposits = 0;
// 	_nbWithdrawals = 0;
// 	_totalAmount += initial_deposit;
// 	_nbAccounts++;
// }

Account::Account(int initial_deposit)
{
	this->_displayTimestamp();
	_accountIndex = _nbAccounts;
	std::cout 	<< " index:" << this->getNbAccounts(); 
	std::cout	<< ";amount:" << initial_deposit << ";created" << std::endl;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_nbAccounts++;
}

Account::~Account()
{
	this->_displayTimestamp();
	std::cout 	<< " index:" << _accountIndex;   
	std::cout	<< ";amount:" << _amount << ";closed" << std::endl;
}
