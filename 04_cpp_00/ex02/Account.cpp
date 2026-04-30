/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:25:02 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/07 11:09:55 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
    return ;
}

int Account::getNbAccounts(void)
{
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
    return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return Account::_totalNbWithdrawals;
}

void Account::_displayTimestamp(void)
{
    std::time_t	timestamp = std::time(0);
	struct tm *datetime = std::localtime(&timestamp);
	char		buffer[20];

	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", datetime);
	std::cout << buffer;
}

void Account::makeDeposit(int deposit)
{
    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;

    Account::_displayTimestamp();
    std::cout   << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit
                << ";deposit:" << deposit << ";amount:" << this->_amount
                << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

int Account::checkAmount(void) const
{
    return this->_amount;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > this->_amount)
    {
        Account::_displayTimestamp();
        std::cout   << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
                    << ";withdrawal:refused" << std::endl;
        return false;
    }

    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;

    Account::_displayTimestamp();
    std::cout   << "index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal
                << ";withdrawal:" << withdrawal << ";amount:" << this->_amount
                << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

    return true;
}
void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout   << "index:" << this->_accountIndex << ";amount:" << this->_amount
                << ";deposits:" << this->_nbDeposits << ";withdrawals:"  << this->_nbWithdrawals 
                << std::endl;
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout   << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount()
                << ";deposits:" << Account::getNbDeposits() << ";withdrawals:"  << Account::getNbWithdrawals() 
                << std::endl;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
    return ;
}
