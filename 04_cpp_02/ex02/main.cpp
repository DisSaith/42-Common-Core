/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:53:33 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/21 10:29:54 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	Fixed			a;
	Fixed const		b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const		c ( a + b );
	
	std::cout << "a + b = " << c << std::endl;
	std::cout << "c - b = " << c - b << std::endl;
	std::cout << "c * 2 = " << c * 2 << std::endl;
	std::cout << "c / 2 = " << c / 2 << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;

	std::cout << "b = " << b << std::endl;
	
	std::cout << "max between a and b = " << Fixed::max( a, b ) << std::endl;
	std::cout << "min between a and b = " << Fixed::min( a, b ) << std::endl;
	
	return (0);
}
