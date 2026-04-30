/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:51:13 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/23 10:51:14 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal( std::string type );
        WrongAnimal( WrongAnimal const& copy );
        ~WrongAnimal();
        
		WrongAnimal& operator=( WrongAnimal const& copy );
		
		std::string		getType() const;
		void	        makeSound() const;
	
	protected:
		std::string		_type;
};

#endif
