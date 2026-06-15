/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:27:34 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/05 09:56:09 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "compare.hpp"

int main( void ) 
{
	std::cout << "----------- TEST 1 ----------" << std::endl;
	int a = 2;
	int b = 3;
	
	std::cout << "[BEFORE SWAP]\n" << "a = " << a << ", b = " << b
			<< std::endl << std::endl;
	::swap( a, b );
	std::cout << "[AFTER SWAP]\n"<< "a = " << a << ", b = " << b
			<< std::endl << std::endl;
	
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::cout << std::endl <<"----------- TEST 2 ----------" << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "[BEFORE SWAP]\n" << "c = " << c << ", d = " << d
			<< std::endl << std::endl;
	::swap(c, d);
	std::cout << "[AFTER SWAP]\n" << "c = " << c << ", d = " << d 
			<< std::endl << std::endl;
	
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << std::endl <<"----------- TEST 3 ----------" << std::endl;
	double	e = 4.12;
	double	f = 4.12;
	
	std::cout << "[BEFORE SWAP]\n" << "e = " << e << ", f = " << f
			<< std::endl << std::endl;
	::swap(e, f);
	std::cout << "[AFTER SWAP]\n" << "e = " << e << ", f = " << f 
			<< std::endl << std::endl;

	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl
			<< "max( e, f ) = " << ::max( e, f ) << std::endl;

	return ( 0 );
}
