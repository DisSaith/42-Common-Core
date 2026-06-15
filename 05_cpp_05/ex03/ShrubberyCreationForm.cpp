/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:48:50 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/27 10:59:10 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//Constructors
ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm( "ShrubberyCreationForm", 145, 137 ), _target( "empty" )
{}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const& target ) 
	: AForm( "ShrubberyCreationForm", 145, 137 ), _target( target )
{}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const& copy )
	: AForm( copy ), _target( copy._target )
{}

//Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

//Overload operator=
ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm const& copy )
{
    if (this != &copy)
    {
		;
    }
    return *this;
}

//Methode
void		ShrubberyCreationForm::executing()
{
	std::string		filename = this->_target + "_shrubbery";
	std::ofstream	file(filename.c_str());
	
	if (file)
	{
		file 
			<< "     ###" << std::endl
			<< "   #o###o#" << std::endl
			<< "  #####o###" << std::endl
			<< " #o###|#/###" << std::endl
			<< "  ####|/#o#" << std::endl
			<< "   # }|{  #" << std::endl
			<< "     }|{  " << std::endl;
		file.close();
	}
}
