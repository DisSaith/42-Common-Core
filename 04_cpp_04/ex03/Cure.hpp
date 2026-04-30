/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:24:38 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 16:08:02 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        virtual ~Cure();
        Cure( Cure const& copy );
		Cure( std::string const& type );
        
		Cure& operator=( Cure const& copy );

		virtual AMateria*	clone() const;
		virtual void		use( ICharacter & target );
};

#endif
