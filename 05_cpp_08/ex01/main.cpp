/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:25:00 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/08 15:49:20 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main( void )
{
	try
	{
		Span			sp(10);
		std::deque<int>	tab(8, 0);

		sp.addNNumbers( tab.begin(), tab.end() );
		sp.addNumber(-2147483648);
		sp.addNumber(2147483647);
	
		std::cout << "longestpan = " << sp.longestSpan() << std::endl;
		std::cout << "shortestpan = " << sp.shortestSpan() << std::endl;
	}
	catch( std::exception & e )
	{
		std::cerr << "Error: " << e.what();
	}
	return (0);
}
