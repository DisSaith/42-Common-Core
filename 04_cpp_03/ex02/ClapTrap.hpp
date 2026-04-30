/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:40:59 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/21 18:02:13 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap( std::string name );
        ClapTrap( std::string name, unsigned int health,
					unsigned int energy, unsigned int attack );
        ClapTrap( ClapTrap const& copy );
        ~ClapTrap();
        
		ClapTrap&	operator=( ClapTrap const& copy );

		void		attack( std::string const& target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );

    protected:
		std::string		_name;
		unsigned int	_healthPts;
		unsigned int	_energyPts;
		unsigned int	_attackDmg;
};

#endif
