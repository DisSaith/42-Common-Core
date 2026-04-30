/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:50:25 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 14:24:53 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
    public:
        Cat();
        Cat( std::string type );
        Cat( Cat const& copy );
        virtual ~Cat();
        
		Cat& operator=( Cat const& copy );
		
		virtual void	makeSound() const;
		void			initBrain() const;
		void			setIdeaBrain( int const& index, std::string const& idea ) const;
		std::string		getIdeaBrain( int const& index ) const;

	private:
		Brain	*_brain;
};

#endif
