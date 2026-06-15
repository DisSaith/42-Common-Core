/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:47:06 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/08 15:44:39 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//Destructor
Span::~Span() {}

//Constructors
Span::Span() : _max_size( 0 ) {}

Span::Span( unsigned int const& N ) : _max_size( N ) {}

Span::Span( Span const& copy )
{
	this->_max_size = copy._max_size;
}

//Overload operator=
Span& Span::operator=( Span const& copy )
{
    if (this != &copy)
    {
		_tab.clear();
		this->_max_size = copy._max_size;
    }
    return *this;
}

//Methodes
void	Span::addNumber( int const& number )
{
	if ( _tab.size() >= this->_max_size )
		throw std::out_of_range("tab reaches already is max size");
	
	_tab.push_back( number );
}

unsigned long long	Span::longestSpan() const
{
	if ( _tab.size() <= 1)
		throw std::logic_error( "there are not enough numbers stored." );
	
	long long max = *std::max_element( _tab.begin(), _tab.end() );
	long long min = *std::min_element( _tab.begin(), _tab.end() );
	return ( static_cast<unsigned long long>( max - min ) );
}

unsigned long long	Span::shortestSpan() const
{
	if ( _tab.size() <= 1)
		throw std::logic_error( "there are not enough numbers stored." );

	std::deque<int>	sorted = _tab;
	std::sort( sorted.begin(), sorted.end() );
	
	unsigned long long	shortest = std::numeric_limits<unsigned long long>::max();
	unsigned long long	diff;

	for( size_t i = 0 ; i < sorted.size() - 1 ; i++ )
	{
		diff = static_cast<long long>( sorted[i + 1] )
				- static_cast<long long>( sorted[i] );
		if ( diff < shortest )
			shortest = diff;
	}
	return ( shortest );
}
