/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:46:44 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/28 10:47:06 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# define DEBUGGING 0

# include <iostream>
# include <string>

class ICharacter;

class AMateria
{
    public:
        AMateria();
        virtual ~AMateria();
        AMateria( AMateria const& copy );
        AMateria( std::string const& type );
        
		AMateria& operator=( AMateria const& copy );

		std::string const&	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use( ICharacter & target );

	protected:
		std::string const	_type;
};

#endif
