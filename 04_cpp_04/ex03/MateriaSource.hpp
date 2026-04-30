/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:24:38 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 16:08:02 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# define MAX_MEMORY 4

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        virtual ~MateriaSource();
        
		virtual void		learnMateria( AMateria *materia );
		virtual AMateria*	createMateria( std::string const& type);
	
	private:
		AMateria	*_materiaLearned[MAX_MEMORY];
		
		MateriaSource( MateriaSource const& copy );
		MateriaSource& operator=( MateriaSource const& copy );
};

#endif
