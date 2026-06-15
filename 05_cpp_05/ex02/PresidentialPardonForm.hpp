/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:48:23 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/27 10:48:25 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        //Constructors
		PresidentialPardonForm();
		PresidentialPardonForm( std::string const& target );
        PresidentialPardonForm( PresidentialPardonForm const& copy );
		
		//Destructor
		virtual ~PresidentialPardonForm();
        
		//Overload operator=
		PresidentialPardonForm& operator=( PresidentialPardonForm const& copy );
    
		//Methodes
		virtual void			executing();

	private:
		//Attributes
		const std::string	_target;
};

#endif
