/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:56:52 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 17:34:03 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# define MAX_INVENTORY 4

class Character : public ICharacter
{
    public:
        Character();
        virtual ~Character();
        Character( Character const& copy );
        Character( std::string const& name);
        
		Character& operator=( Character const& copy );

		virtual std::string const&	getName() const;
		virtual void				equip( AMateria* m );
		virtual void				unequip( int idx );
		virtual void				use( int idx, ICharacter & target );
		AMateria*					copyInventory( int const& idx ) const;
		AMateria*					saveAddress( int const& idx ) const;

    private:
		AMateria			*_inventory[MAX_INVENTORY];
		std::string const	_name;
};

#endif
