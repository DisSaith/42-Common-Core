/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:12:24 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 11:56:45 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

std::string		intoString( int const& n )
{
	std::ostringstream os;
	os << n;
	return (os.str());
}

Brain::Brain() : _maxArray( 100 )
{
	std::cout << "Brain default constructor." << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor." << std::endl;
	return ;
}

Brain::Brain( Brain const& copy ) : _maxArray( 100 )
{
	std::cout << "Brain copy constructor." << std::endl;
    for (int i = 0 ; i < _maxArray ; i++)
		this->setIdea( i, copy.getIdea( i ));
}

Brain& Brain::operator=( Brain const& copy )
{
    if (this != &copy)
    {
		std::cout << "Brain overload operator=." << std::endl;
		for (int i = 0 ; i < _maxArray ; i++)
			this->setIdea( i, copy.getIdea( i ));
    }
    return *this;
}

int				Brain::getMaxArray( void ) const
{
	return (this->_maxArray);
}

std::string		Brain::getIdea( int const& index ) const
{
	if (index < 0 || index > _maxArray - 1)
	{
		std::cout << "[getIdea]	Wrong index sorry." << std::endl;
		return ( "NULL" );
	}
	return (this->_ideas[index]);
}

void			Brain::setIdea( int const& index, std::string const& idea )
{
	if (index < 0 || index > _maxArray - 1)
	{
		std::cout << "[setIdea]	Wrong index sorry." << std::endl;
		return ;
	}
	this->_ideas[index] = idea;
}

void			Brain::initIdeas( void )
{
	for( int i = 0 ; i < _maxArray ; i++ )
		this->_ideas[i] = "idea" + intoString( i );
}
