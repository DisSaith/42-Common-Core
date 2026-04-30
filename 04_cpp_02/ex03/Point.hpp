/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 10:52:11 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/20 17:49:19 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point
{
    public:
        Point();
        Point( Point const& copy );
		Point( float const& x, float const& y );
        ~Point();

		Point& operator=( Point const& copy );

		float		getX( void ) const;
		float		getY( void ) const;
		int			toInt( float const& value ) const;
		void		displayAttributes(std::ostream & flux) const;
		static bool	checkCoordonates( Point const& a, Point const& b, 
										Point const& c, Point const& point );
		static void	displayMap( Point const& a, Point const& b, 
						Point const& c, Point const& point );

    private:
		Fixed const	_x;
		Fixed const _y;
};

bool			bsp( Point const a, Point const b,
					Point const c, Point const point );
std::ostream&	operator<<( std::ostream & flux, Point const& a );

#endif
