/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:50:56 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/23 10:50:57 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main( void )
{
	std::cout << "\033[34m[REALS ANIMALS]\033[0m" << std::endl;
	std::cout << "\033[34m[CREATION OBJECTS]\033[0m" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl << "\033[34m[TESTS]\033[0m" << std::endl;
	std::cout << "j type = " << j->getType() << " " << std::endl;
	std::cout << "i type = " << i->getType() << " " << std::endl;
	std::cout << "meta type = " << meta->getType() << " " << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl << "\033[34m[DESTRUCTION OBJECTS]\033[0m" << std::endl;
	delete meta;
	delete i;
	delete j;
	
	std::cout << std::endl << "\033[34m[WRONGS ANIMALS]\033[0m" << std::endl;
	std::cout << "\033[34m[CREATION OBJECTS]\033[0m" << std::endl;
	const WrongAnimal* wrong1 = new WrongAnimal();
	const WrongAnimal* wrong2 = new WrongCat();
	
	std::cout << std::endl << "\033[34m[TESTS]\033[0m" << std::endl;
	std::cout << "wrong1 type = " << wrong1->getType() << " " << std::endl;
	std::cout << "wrong2 type = " << wrong2->getType() << " " << std::endl;
	
	wrong1->makeSound();
	wrong2->makeSound(); //WrongCat make a wrong sound because makeSound isn't virtual
	std::cout << std::endl << "\033[34m[DESTRUCTION OBJECTS]\033[0m" << std::endl;
	delete wrong1;
	delete wrong2; //only one destructor called because no virtual as well

	return (0);
}
