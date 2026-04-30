/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:40:59 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/21 19:46:16 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap( std::string name );
        FragTrap( std::string name, unsigned int health,
				unsigned int energy, unsigned int attack);
        FragTrap( FragTrap const& copy );
        ~FragTrap();
        
		FragTrap&	operator=( FragTrap const& copy );

		void		highFivesGuys( void ) const;

    private:
};

#endif
