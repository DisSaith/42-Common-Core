/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:50:25 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/23 10:50:27 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog( std::string type );
        Dog( Dog const& copy );
        virtual ~Dog();
        
		Dog& operator=( Dog const& copy );
		
		virtual void	makeSound() const;
};

#endif
