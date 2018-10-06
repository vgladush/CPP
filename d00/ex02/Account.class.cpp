/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:34:13 by vgladush          #+#    #+#             */
/*   Updated: 2018/07/23 20:46:39 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int		Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

Account::Account( int initial_deposit ): _amount(initial_deposit) {
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += this->_amount;
	std::cout << "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";" << "created" << std::endl;
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	Account::_nbAccounts -= 1;
	Account::_totalAmount -= this->_amount;
	std::cout << "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";" << "closed" << std::endl;
}

void	Account::_displayTimestamp( void ) {
	std::time_t t = std::time(0);
	std::tm	*now = std::localtime(&t);
	std::cout << "[" << 1900 + now->tm_year;
	std::cout << (now->tm_mon  + 1 < 10 ? "0" : "") << now->tm_mon + 1
	<< (now->tm_mday < 10 ?  "0" : "") << now->tm_mday
	<< (now->tm_hour < 10 ? "_0" : "_") << now->tm_hour
	<< (now->tm_min < 10 ?  "0" : "") << now->tm_min
	<< (now->tm_sec < 10 ?  "0" : "") << now->tm_sec << "] ";
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:"
	<< Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits
	<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl; 
}

void	Account::displayStatus (void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
	<< this->_amount << ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	Account::_displayTimestamp();
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	this->_amount += deposit;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
	<< ";deposit:" << deposit << ";amount:" << this->_amount
	<< ";nb_deposits:" << this->_nbDeposits << std::endl;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {	
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:"
	<< this->_amount << ";withdrawal:";
	if (withdrawal > this->_amount) {
		std::cout << "refused" << std::endl;
		return false;
	}
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	std::cout << withdrawal << ";amount:" << (this->_amount -= withdrawal)
	<< ";nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}
