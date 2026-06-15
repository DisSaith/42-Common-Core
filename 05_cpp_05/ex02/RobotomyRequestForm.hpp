/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:48:41 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/27 10:48:43 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        //Constructors
		RobotomyRequestForm();
		RobotomyRequestForm( std::string const& target );
        RobotomyRequestForm( RobotomyRequestForm const& copy );
		
		//Destructor
		virtual ~RobotomyRequestForm();
        
		//Overload operator=
		RobotomyRequestForm& operator=( RobotomyRequestForm const& copy );
    
		//Methodes
		virtual void			executing();

	private:
		//Attributes
		const std::string	_target;
		int					_robotomized;
};

#endif
