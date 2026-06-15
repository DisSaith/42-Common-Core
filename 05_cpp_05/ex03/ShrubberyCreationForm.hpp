/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:48:55 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/27 10:48:57 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
    public:
        //Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string const& target );
        ShrubberyCreationForm( ShrubberyCreationForm const& copy );
		
		//Destructor
		virtual ~ShrubberyCreationForm();
        
		//Overload operator=
		ShrubberyCreationForm& operator=( ShrubberyCreationForm const& copy );
    
		//Methodes
		virtual void			executing();

	private:
		//Attributes
		const std::string	_target;
};

#endif
