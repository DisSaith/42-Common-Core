/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:48:06 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/27 10:58:49 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class AForm
{
    public:
        //Constructors
		AForm();
        AForm( AForm const& copy );
		AForm( std::string const& name,
				unsigned short const& sign_grade,
				unsigned short const& exec_grade );
		
		//Destructor
		virtual ~AForm();
        
		//Overload operator=
		AForm& operator=( AForm const& copy );
    
		//Getters
		const std::string		getName() const;
		bool					getSign() const;
		unsigned short			getSignGrade() const;
		unsigned short			getExecGrade() const;

		//Methodes
		void			beSigned( Bureaucrat const& a );
		void			execute( Bureaucrat const& a );
		virtual void	executing() = 0;

		//Nested class exception
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class AFormAlreadySigned : public std::exception
		{
			virtual const char* what() const throw();
		};
		class AFormNotSigned : public std::exception
		{
			virtual const char* what() const throw();
		};

	private:
		const std::string		_name;
		bool					_sign;
		const unsigned short	_sign_grade;
		const unsigned short	_exec_grade;
};

std::ostream&	operator<<( std::ostream & out, AForm const& form );

#endif
