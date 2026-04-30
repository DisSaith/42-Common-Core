/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:50:25 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 14:25:39 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
    public:
        Dog();
        Dog( std::string type );
        Dog( Dog const& copy );
        virtual ~Dog();
        
		Dog& operator=( Dog const& copy );
		
		virtual void	makeSound() const;
		void			initBrain() const;
		void			setIdeaBrain( int const& index, std::string const& idea ) const;
		std::string		getIdeaBrain( int const& index ) const;

	private:
		Brain	*_brain;
};

#endif
