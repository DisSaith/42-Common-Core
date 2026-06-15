/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:48:55 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/09 16:05:05 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main( int argc, char **argv )
{
	if ( argc > 2 )
	{
		std::cerr << "Usage: ./btc filename" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange	bitcoin;
		bitcoin.openFile( argv[1] );
	}
	catch( std::exception & e )
	{
		std::cerr << "Error: " << e.what();
	}
	return (0);
}
