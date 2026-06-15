/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:17:08 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/03 14:28:24 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template< typename A  >
void	iter( A * array, size_t const length, void (*func)( A & ))
{
	size_t	i = 0;
	while ( i < length )
	{
		(*func)(array[i]);
		i++;
	}
}

template< typename A  >
void	iter( A * array, size_t const length, void (*func)( A const& ))
{
	size_t	i = 0;
	while ( i < length )
	{
		(*func)(array[i]);
		i++;
	}
}

template< typename T >
void	incrementation( T & param ) { param++; }

template< typename T >
void	display( T const& param ) { std::cout << param << std::endl; }

#endif

