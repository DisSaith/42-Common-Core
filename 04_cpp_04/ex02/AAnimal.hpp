/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:50:06 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 14:26:50 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
    public:
        AAnimal();
        AAnimal( std::string type );
        AAnimal( AAnimal const& copy );
        virtual ~AAnimal();
        
		AAnimal& operator=( AAnimal const& copy );
		
		std::string		getType() const;
		virtual void	makeSound() const = 0;
	
	protected:
		std::string		_type;
};

#endif
