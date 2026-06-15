/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:41:44 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/27 10:43:22 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
    public:
        //Constructors
		Form();
        Form( Form const& copy );
		Form( std::string const& name,
				unsigned short const& sign_grade,
				unsigned short const& exec_grade );
		
		//Destructor
		~Form();
        
		//Overload operator=
		Form& operator=( Form const& copy );
    
		//Getters
		const std::string		getName() const;
		bool					getSign() const;
		unsigned short			getSignGrade() const;
		unsigned short			getExecGrade() const;

		//Methodes
		void					beSigned( Bureaucrat const& a );

		//Nested class exception
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class FormAlreadySigned : public std::exception
		{
			virtual const char* what() const throw();
		};

	private:
		//Attributes
		const std::string		_name;
		bool					_sign;
		const unsigned short	_sign_grade;
		const unsigned short	_exec_grade;
};

std::ostream&	operator<<( std::ostream & out, Form const& form );

#endif
