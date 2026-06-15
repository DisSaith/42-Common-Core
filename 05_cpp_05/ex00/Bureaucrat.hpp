/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 09:59:44 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/22 15:22:06 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
    public:
        //Constructors
		Bureaucrat();
        Bureaucrat( Bureaucrat const& copy );
		Bureaucrat( std::string const& name, unsigned short const& grade );
        
		//Destructor
        ~Bureaucrat();

		//Overload operator=
		Bureaucrat&		operator=( Bureaucrat const& copy );

		//Getters
		const std::string	getName() const;
		unsigned short		getGrade() const;

		//Increment & Decrement
		void				increment();
		void				decrement();

		//Nested class exception
		class GradeTooLowException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};

    private:
		//Attributes
		const std::string	_name;
		unsigned short		_grade;
};

//Overload operator<<
std::ostream&	operator<<( std::ostream & out, Bureaucrat const& crat );

#endif
