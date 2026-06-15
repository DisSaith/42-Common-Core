/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:31:58 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/03 18:00:31 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main( void )
{
	try 
	{
		std::cout << "---------- TEST 1 ----------\n";
		Array<int> test1;
		Array<int> test2( 10 );
		for ( size_t i = 0 ; i < 10 ; i++ )
		{
			test2[i] = i;
			std::cout << "test2[" << i << "] = " << test2[i] << std::endl;
		}
		std::cout << "test2(int) size = " << test2.size() << std::endl
				<< "test1(int) size = " << test1.size() << std::endl;
		test2[10] = 10; //will throw an exception out_of_range
	}
	catch ( std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try 
	{
		std::cout << "\n---------- TEST 2 ----------\n";
		Array<std::string> test3( 5 );
		for ( size_t i = 0 ; i < 5 ; i++ )
		{
			test3[i] = "string_" + std::string(1, i + '0');
			std::cout << "test3[" << i << "] = " << test3[i] << std::endl;
		}
		std::cout << "test3(std::string) size = " << test3.size() << std::endl;
		std::cout << std::endl;

		Array<std::string> test4;
		test4 = test3;
		for (size_t i = 0 ; i < 5 ; i++)
			std::cout << "test4[" << i << "] = " << test4[i] << std::endl;
		std::cout << "test4(copy of test3) size = " << test4.size() << std::endl;
	}
	catch ( std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
