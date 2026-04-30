/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:53:33 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/21 10:06:36 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main( void )
{
	Point	a( 4.2f, 5.5f );
	Point	b( 8.2f, 9.5f );
	Point	c( 9.2f, 1.5f );
	Point	point( 9.5f, 1.6f );
	bool	result = bsp( a, b, c, point );

	std::cout << "a -> " << a;
	std::cout << "b -> " << b;
	std::cout << "c -> " << c;
	std::cout << "point -> " << point << std::endl;
	
	Point::displayMap( a, b, c, point );
	
	std::cout << "point in the triangle ? >> ";
	if ( result == false )
		std::cout << "No" << std::endl;
	else
		std::cout << "Yes" << std::endl;
	
	return (0);
}
