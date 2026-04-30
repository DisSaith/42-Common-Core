/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:41:57 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/20 17:20:35 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
    // Calcul du produit vectoriel pour chaque segment
    // (b.x - a.x) * (point.y - a.y) - (b.y - a.y) * (point.x - a.x)
    
    Fixed d1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) -
				(b.getY() - a.getY()) * (point.getX() - a.getX());
    Fixed d2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) -
				(c.getY() - b.getY()) * (point.getX() - b.getX());
    Fixed d3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) -
				(a.getY() - c.getY()) * (point.getX() - c.getX());

    // Le point est à l'intérieur si les trois signes sont identiques
    // ET qu'aucun n'est égal à 0 (car 0 = sur l'arête)
	if ((d1 < 0 && d2 < 0 && d3 < 0) || (d1 > 0 && d2 > 0 && d3 > 0))
			if (d1 != 0 && d2 != 0 && d3 != 0)
				return (true);
	return (false);
}
