/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:40:59 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/21 19:55:24 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
        DiamondTrap( std::string name );
        DiamondTrap( DiamondTrap const& copy );
        virtual ~DiamondTrap();
        
		    DiamondTrap&	operator=( DiamondTrap const& copy );

        using ScavTrap::attack;
        void  whoAmI() const;
    private:
        std::string _name;
};

#endif