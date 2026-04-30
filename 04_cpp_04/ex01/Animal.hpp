/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:50:06 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/23 10:50:07 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
    public:
        Animal();
        Animal( std::string type );
        Animal( Animal const& copy );
        virtual ~Animal();
        
		Animal& operator=( Animal const& copy );
		
		std::string		getType() const;
		virtual void	makeSound() const;
	
	protected:
		std::string		_type;
};

#endif
