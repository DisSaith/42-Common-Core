/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 10:52:02 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/20 17:54:42 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	return ;
}

Point::~Point()
{
	return ;
}

Point::Point( float const& x, float const& y ) : _x(x), _y(y)
{
	return ;
}

Point::Point( Point const& copy ) : _x(copy._x), _y(copy._y)
{
	return ;
}

Point& Point::operator=( Point const& copy )
{
    if (this != &copy)
    {
		return *this;
    }
    return *this;
}

float	Point::getX( void ) const
{
	return (this->_x.toFloat());
}

float	Point::getY( void ) const
{
	return (this->_y.toFloat());
}

/* Return the conversion of a float into an int multiplied by 10*/
int		Point::toInt( float const& value ) const
{
	return ((roundf(value * 256) * 10) / 256);
}

void	Point::displayAttributes( std::ostream & flux ) const
{
	flux << "x = " << this->_x << ", y = " << this->_y << std::endl;
}

bool	Point::checkCoordonates( Point const& a, Point const& b,
								Point const& c, Point const& point )
{
	if (a.getX() > 10.0 || a.getY() > 10.0 || a.getX() < 0.0 || a.getY() < 0.0 
		|| b.getX() > 10.0 || b.getY() > 10.0 || b.getX() < 0.0 || b.getY() < 0.0 
		|| c.getX() > 10.0 || c.getY() > 10.0 || c.getX() < 0.0 || c.getY() < 0.0 
		|| point.getX() > 10.0 || point.getY() > 10.0
		|| point.getX() < 0.0 || point.getY() < 0.0)
		return (false);
	return (true);

}

/* Work only with coordonates between 0.1 and 9.9 for x and y*/
void	Point::displayMap( Point const& a, Point const& b, 
								Point const& c,	Point const& point )
{
	if (Point::checkCoordonates(a, b, c, point) == false)
	{
		std::cout << "This function need coordonates between 0.1 and 9.9"
					<< std::endl;
		return ;
	}
	char	tab[100][100];
	int v1X = a.toInt(a.getX()), v1Y = a.toInt(a.getY());
	int v2X = b.toInt(b.getX()), v2Y = b.toInt(b.getY());
	int v3X = c.toInt(c.getX()), v3Y = c.toInt(c.getY());
	int pX = point.toInt(point.getX()), pY = point.toInt(point.getY());
	
	for (int i = 0 ; i < 100 ; i++)
		for (int j = 0 ; j < 100 ; j++)
		{
			if (j == 99)
			{
				tab[i][j] = '\0';
				continue ;
			}
			tab[i][j] = '.';
		}
	tab[v1Y][v1X] = 'a';
	tab[v2Y][v2X] = 'b';
	tab[v3Y][v3X] = 'c';
	tab[pY][pX] = 'p';
	
	for (int i = 0 ; i < 100 ; i++)
		for (int j = 0 ; j < 100 ; j++)
		{
			if (j == 99)
			{
				std::cout << std::endl;
				continue ;
			}
			std::cout << tab[i][j];
		}
}

std::ostream& operator<<( std::ostream & flux, Point const& a )
{
	a.displayAttributes(flux);
	return flux;
}
