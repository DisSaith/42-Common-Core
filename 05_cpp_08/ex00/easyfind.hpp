/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:39:53 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/08 11:03:34 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <ctime>
# include <cstdlib>
# include <exception>

template < typename T >
typename T::iterator	easyfind( T const& tab, int const& to_find )
{
	typename T::iterator finded = std::find(tab.begin(), tab.end(), to_find);
	/* Optional */
	if ( finded == tab.end() )
		throw std::logic_error(" not finded in tab.");
	/***********/
	return ( finded );
}

template < typename T >
typename T::iterator	easyfind( T & tab, int const& to_find )
{
	typename T::iterator finded = std::find(tab.begin(), tab.end(), to_find);
	/* Optional */
	if ( finded == tab.end() )
		throw std::logic_error(" not finded in tab.");
	/***********/
	return ( finded );
}

//Functor to create an int tab randomised
class Randomise
{
	public:
		Randomise( int const& max ) : _max( max ) {}
		int	operator()() { return ( std::rand() % _max ); }
	private:
		Randomise() : _max( 0 ) {}
		int const	_max;
};

//Functor to display container's elements
template < typename T >
class Display
{
	public:
		void	operator()(T const& a) { std::cout << a << std::endl; }
};

#endif
