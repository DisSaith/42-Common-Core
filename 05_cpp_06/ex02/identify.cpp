/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 09:55:27 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/03 09:55:42 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "C.hpp"

Base	*generate( void )
{
	//use current time as seed to have a random number 
	//each time we run the program
	std::srand(time(0));
	int		random = std::rand() % 3; //random between 0 and 2
	
	if ( random == 0 )
		return ( new A );
	else if ( random == 1 )
		return ( new B );
	else
		return ( new C );
}

void	identify( Base * p )
{
	if ( dynamic_cast<A*>( p ) != NULL )
		std::cout << "A" << std::endl;	
	else if ( dynamic_cast<B*>( p ) != NULL )
		std::cout << "B" << std::endl;
	else if ( dynamic_cast<C*>( p ) != NULL )
		std::cout << "C" << std::endl;
}

void	identify( Base & p )
{
	try {
		(void)dynamic_cast<A&>( p );
		std::cout << "A" << std::endl;
		return ;
	}
	catch ( std::exception & e ) {}
	try {
		(void)dynamic_cast<B&>( p );
		std::cout << "B" << std::endl;
		return ;
	}
	catch ( std::exception & e ) {}
	try {
		(void)dynamic_cast<C&>( p );
		std::cout << "C" << std::endl;
		return ;
	}
	catch ( std::exception & e ) {}
}
