/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:27:26 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/03 13:02:53 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_HPP
# define COMPARE_HPP

template< typename T >
void	swap( T & a, T & b )
{
	T	tmp;

	tmp = b;
	b = a;
	a = tmp;
}

template< typename T >
T const&	min( T const& a, T const& b )
{
	if ( a < b )
		return ( a );
	return ( b );
}

template< typename T >
T const&	max( T const& a, T const& b )
{
	if ( a > b )
		return ( a );
	return ( b );
}

#endif
