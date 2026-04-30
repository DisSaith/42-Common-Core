/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:40:59 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/21 19:55:24 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap( std::string name );
        ScavTrap( std::string name, unsigned int health,
				unsigned int energy, unsigned int attack);
        ScavTrap( ScavTrap const& copy );
        virtual ~ScavTrap();
        
		ScavTrap&	operator=( ScavTrap const& copy );

		void		attack( std::string const& target );
		void		guardGate();

    protected:
		bool		_gateKeeping;
};

#endif