/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:50:56 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 14:14:44 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main( void )
{
	/********************DEEP COPY***************************/
	std::cout << "\033[34m[TEST DEEP COPY]\033[0m" << std::endl;
	std::cout << "\033[34m[CREATION OBJECT ROBERT]\033[0m" << std::endl;
	const Dog *robert = new Dog( "Robert" );
	
	std::cout << robert->getType() << ": sets one idea." << std::endl;
	robert->setIdeaBrain( 0, "waf waf" ); //set waf waf
	std::cout << robert->getType() << " idea[0] = " 
			<< robert->getIdeaBrain( 0 ) << std::endl; 
	
	std::cout << "\033[34m[CREATION OBJECT ROBERT_COPY]\033[0m" << std::endl;
	const Dog *robert_copy = new Dog (*robert);
	
	std::cout << "\033[34m[DESTRUCTION OBJECT ROBERT]\033[0m" << std::endl;
	delete robert;
	
	std::cout << "Robert_copy has same ideas (deep copy) even if robert is destroyed." << std::endl;
	std::cout << robert_copy->getType() << " idea[0] = " 
			<< robert_copy->getIdeaBrain( 0 ) << std::endl; 
	//he has waf waf as well (thanks to deep copy)
	
	std::cout << "\033[34m[DESTRUCTION OBJECT ROBERT_COPY]\033[0m" << std::endl;
	delete robert_copy;

	/***********SHALLOW COPY****************/
	/*const Dog *colun = new Dog( "Colun" );
	const Dog *coldeux = new Dog( "Coldeux" );
	std::cout << colun->getType() << ": sets an idea." << std::endl;
	colun->setIdeaBrain( 0, "test" ); //set an idea to colun
	coldeux = colun; //shallow copy, the same pointeur address and values
	std::cout << "Old Coldeux (now a shallow copy of Colun): idea[0] = " 
			<< coldeux->getIdeaBrain( 0 ) << std::endl;
	delete colun;
	delete coldeux;*/

	
	/********************ARRAY OF POINTERS*************************/
	std::cout << std::endl << "\033[34m[TEST ARRAY OF POINTERS ANIMAL]\033[0m" << std::endl;
	std::cout << "\033[34m[CREATION OBJECTS]\033[0m" << std::endl;
	Animal	*array[10];
	for (int i = 0 ; i < 10 ; i++)
	{
		if (i % 2)
			array[i] = new Cat();
		else
			array[i] = new Dog();
	}
	std::cout << "\033[34m[DESTRUCTION OBJECTS]\033[0m" << std::endl;
	for (int i = 0 ; i < 10 ; i++)
	{
		delete  array[i];
	}
	//no leaks at the end of the programm if it's working

	return (0);
}
