/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:12:17 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 11:05:29 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include <sstream>

class Brain
{
    public:
        Brain();
        Brain( Brain const& copy );
        virtual ~Brain();
        
		Brain& operator=( Brain const& copy );

		int				getMaxArray( void ) const;
		std::string		getIdea( int const& index ) const;
		void			setIdea( int const& index, std::string const& idea );
		void			initIdeas( void );

    private:
		std::string	_ideas[100];
		const int	_maxArray;
};

std::string	intoString( int const& n );

#endif
