/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 09:54:40 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/03 09:54:41 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main( void )
{
	std::cout << "----------- TEST 1 ------------" << std::endl;
	Data		test( 42, 12.5, "Antoine" );
	
	std::cout << "[Before serialize]" << std::endl << test << std::endl;
	
	uintptr_t	ptr = Serializer::serialize( &test );
	Data		*p = Serializer::deserialize( ptr );
	
	std::cout << "[After deserialize]" << std::endl
			<< "Id: " << p->getId() << std::endl
			<< "Name: " << p->getName() << std::endl
			<< "Value: " << p->getValue() << std::endl << std::endl
			<< "test addr -> " << &test << std::endl
			<< "p addr (deserialize return addr) -> " << p << std::endl;
	
	std::cout << std::endl <<"----------- TEST 2 ------------" << std::endl;
	Data		test2( 17, 3.14, "Boris" );
	void		*p1 = static_cast<void*>( &test2 );
	uintptr_t	 p2 = Serializer::serialize( &test2 );
	Data		*p3 = Serializer::deserialize( p2 );
	Data		*p4 = dynamic_cast<Data*>( &test2 );
	Data		*p5 = reinterpret_cast<Data*>( &test2 );
	std::cout << "(void *) p1 (static_cast) addr -> " << p1 << std::endl
			<< "(Data *) p3 (deserialize) addr -> " << p3 << std::endl
			<< "(Data *) p4 (dynamic_cast) addr -> " << p4 << std::endl
			<< "(Data *) p5 (reinterpret_cast) addr -> " << p5 << std::endl
			<< "(Data) test2 addr -> " << &test2 << std::endl << std::endl;
	
	std::cout << "[Before serialize]" << std::endl << test2 << std::endl
			<< "[After deserialize]" << std::endl
			<< "Id: " << p3->getId() << std::endl
			<< "Name: " << p3->getName() << std::endl
			<< "Value: " << p3->getValue() << std::endl << std::endl;

	return (0);
}

