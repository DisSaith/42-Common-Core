/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:24:38 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/28 10:28:54 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "ICharacter.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        virtual ~Ice();
        Ice( Ice const& copy );
		Ice( std::string const& type );
        
		Ice& operator=( Ice const& copy );

		virtual AMateria*	clone() const;
		virtual void		use( ICharacter & target );
	
};

#endif
