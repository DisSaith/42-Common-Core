/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:09:59 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 17:30:28 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}

		virtual void		learnMateria( AMateria *materia) = 0;
		virtual AMateria*	createMateria( std::string const& type ) = 0;
};

#endif
