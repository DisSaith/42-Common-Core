/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 09:59:44 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/27 14:30:40 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
    public:
        //Constructors
		Intern();
        Intern( Intern const& copy );
        
		//Destructor
        ~Intern();

		//Overload operator=
		Intern&		operator=( Intern const& copy );

		//Methodes
		static AForm	*makePresidentialPardon( std::string const& target );
		static AForm	*makeRobotomyRequest( std::string const& target );
		static AForm	*makeShrubberyCreation( std::string const& target );
		AForm			*makeForm( std::string const& formName, std::string const& target );

		//Nested class exception
		class	FormNameNotRecognised : public std::exception
		{
			public:
			FormNameNotRecognised();
			FormNameNotRecognised( std::string const& formName );
			virtual ~FormNameNotRecognised() throw();
			virtual const char* what() const throw();
			private:
			std::string		_errorMessage;
		};
};

#endif
