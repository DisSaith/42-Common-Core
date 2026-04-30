/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:46:39 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 16:02:26 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	if (DEBUGGING)
		std::cout << "MateriaSource default constructeur." << std::endl;
	for (int i = 0 ; i < MAX_MEMORY ; i++)
		_materiaLearned[i] = NULL;
}

MateriaSource::~MateriaSource()
{	
	if (DEBUGGING)
		std::cout << "MateriaSource destructor." << std::endl;
	for ( int i = 0 ; i < MAX_MEMORY ; i++ )
	{
		if (this->_materiaLearned[i] != NULL)
			delete this->_materiaLearned[i];
	}
}

MateriaSource::MateriaSource( MateriaSource const& copy )
{	
	if (DEBUGGING)
		std::cout << "MateriaSource copy constructeur." << std::endl;
	for ( int i = 0 ; i < MAX_MEMORY ; i++ )
		this->_materiaLearned[i] = copy._materiaLearned[i]->clone();
}

MateriaSource& MateriaSource::operator=( MateriaSource const& copy )
{
    if (this != &copy)
    {
		if (DEBUGGING)
			std::cout << "MateriaSource overload operator=" << std::endl;	
		for ( int i = 0 ; i < MAX_MEMORY ; i++ )
		{
			if (this->_materiaLearned[i] != NULL)
				delete this->_materiaLearned[i];
			this->_materiaLearned[i] = copy._materiaLearned[i]->clone();
		}
    }
    return *this;
}

void			MateriaSource::learnMateria( AMateria *materia )
{
	for ( int i = 0 ; i < MAX_MEMORY ; i++ )
	{
		if (this->_materiaLearned[i] == NULL && materia != NULL)
		{
			this->_materiaLearned[i] = materia;
			std::cout << "MateriaSource learned " << _materiaLearned[i]->getType() << std::endl;
			return ;
		}
	}
	if (materia != NULL)
	{
		delete materia;
		std::cout << "MateriaSource can't learn anymore." << std::endl;
	}
}

AMateria*		MateriaSource::createMateria( std::string const& type )
{
	if (type == "cure" || type == "ice")
	{
		for (int i = 0 ; i < MAX_MEMORY ; i++)
		{
			if (this->_materiaLearned[i] != NULL
				&& this->_materiaLearned[i]->getType() == type)
				return ( this->_materiaLearned[i]->clone() );
		}
		std::cout << "MateriaSource didn't learned " << type << " yet." << std::endl;
	}
	std::cout << "Wrong materia's type asked." << std::endl;
	return ( NULL );
}
