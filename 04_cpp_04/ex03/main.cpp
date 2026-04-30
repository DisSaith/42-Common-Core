/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:55:07 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/28 10:46:31 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	main( void )
{
	/****************SUBJECT TESTS****************/
	std::cout << "[SUBJECT TESTS]" << std::endl;
	AMateria *tmp;
	IMateriaSource *src = new MateriaSource();
	ICharacter *me = new Character("me");
	ICharacter *bob = new Character("bob");

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	std::cout << std::endl;

	/****************SIMPLE TESTS****************/
	std::cout << "[SIMPLE TESTS]" << std::endl;
	Character	jules( "Jules" );
	Character	patrick( "Patrick" );
	AMateria	*ptr = new Cure;
	AMateria	*ptr2 = new Cure;
	AMateria	*ptr3 = new Ice;
	AMateria	*ptr4 = new Ice;
	AMateria	*ptr5 = new Ice;

	jules.equip( ptr );
	jules.equip( ptr2 );
	jules.equip( ptr3 );
	jules.equip( ptr4 );
	jules.equip( ptr5 );
	jules.unequip( 3 );
	Character	jules_copy( jules ); //deep copy
	jules_copy.use( 0, jules );
	jules.use( 0, patrick );
	jules.unequip( 0 ); //unequip ptr
	jules_copy.equip( ptr ); //equip ptr
	AMateria	*save = jules_copy.saveAddress( 3 ); //save address before unequip
	jules_copy.unequip( 3 );

	delete ptr4;
	delete ptr5;
	delete save;

	return (0);
}
