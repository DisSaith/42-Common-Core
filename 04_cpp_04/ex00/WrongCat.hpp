/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:51:01 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/23 10:51:02 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat( std::string type );
        WrongCat( WrongCat const& copy );
        ~WrongCat();
        
		WrongCat& operator=( WrongCat const& copy );
		
		void	makeSound() const;
};

#endif
