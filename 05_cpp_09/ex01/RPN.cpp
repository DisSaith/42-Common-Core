/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:57:03 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/12 14:00:45 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//Destructor
RPN::~RPN() {}

//Default constructor
RPN::RPN() : _numbers() {}

//Private copy constructor
RPN::RPN( RPN const& copy ) { (void)copy; }

//Private overload operator=
RPN& RPN::operator=( RPN const& copy ) { (void)copy; return *this; }

//Static methods
static int		addition( int & a, int & b )
{
	return ( a + b );
}

static int		subtraction( int & a, int & b )
{
	return ( a - b );
}

static int		division( int & a, int & b )
{
	if ( b == 0 )
		throw	std::logic_error("division by 0.");
	return ( a / b );
}

static int		multiplication( int & a, int & b )
{
	return ( a * b );
}

//Methods
void	RPN::checkArgument( char *av )
{
	size_t	i = 0;
	int		lastIsSpace = 1;
	int		digits = 0;
	int		operations = 0;

	while ( av[i] )
	{
		if ( !std::isdigit( av[i] ) && av[i] != ' ' && av[i] != '*'
			&& av[i] != '-' && av[i] != '/' && av[i] != '+' )
			throw std::invalid_argument("at least one input is invalid.");
		if ( std::isdigit( av[i] ) )
		{
			if ( !lastIsSpace )
				throw std::invalid_argument("at least one input is invalid.");
			digits++;
			lastIsSpace = 0;
		}
		else if ( av[i] == '-' || av[i] == '+' || av[i] == '*' || av[i] == '/' )
		{
			if ( !lastIsSpace )
				throw std::invalid_argument("at least one input is invalid.");
			operations++;
			lastIsSpace = 0;
		}
		else
			lastIsSpace = 1;
		i++;
	}
	if ( digits - 1 != operations )
		throw std::invalid_argument("wrong number of inputs.");
}

void	RPN::doOperations( char *av )
{
	size_t	i = 0;
	int		result = 0;
	int		b = 0;
	int		a = 0;

	while ( av[i] )
	{
		if ( std::isdigit(av[i]) == true )
			_numbers.push( av[i] - '0' );
		else if ( av[i] == '-' || av[i] == '+' || av[i] == '*' || av[i] == '/' )
		{
			if ( _numbers.size() < 2 )
				throw std::logic_error("not enough tokens on the stack.");
			b = _numbers.top();
			_numbers.pop();
			a = _numbers.top();
			_numbers.pop();
			if ( av[i] == '+' )
				result = addition( a, b );
			if ( av[i] == '-' )
				result = subtraction( a, b );
			if ( av[i] == '*' )
				result = multiplication( a, b );
			if ( av[i] == '/' )
				result = division( a, b );
			_numbers.push( result );
		}
		i++;
	}
	if ( _numbers.size() != 1 )
		throw std::logic_error("invalid expression state at the end.");
	std::cout << _numbers.top() << std::endl;
}
