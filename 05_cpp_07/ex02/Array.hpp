/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:31:48 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/05 10:25:10 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>
# include <stdexcept>

template < typename T >
class Array
{
    public:
		//Constructors
		Array() : _tab( 0 ), _size( 0 ) {}
		Array( unsigned int const& n ) : _tab( new T[n] ), _size( n ) {}
		Array( Array const& copy ) {
			this->_size = copy._size;
			this->_tab = new T[_size];
			for ( size_t i = 0 ; i < _size ; i++ )
				this->_tab[i] = copy._tab[i];
		}
		//Default destructor
		~Array() { delete [] this->_tab; }

		//Overload operator[]
		T&		operator[]( size_t const& index ) { 
			if ( index >= _size )
				throw std::out_of_range("index is out of bounds");
			return ( this->_tab[index] ); 
		}
		//Overloard operator=
		Array&	operator=( Array const& copy ) { 
			if ( this != &copy )
			{
				if (this->_tab)
					delete [] this->_tab;
				this->_size = copy.size();
				this->_tab = new T[_size];
				for ( size_t i = 0 ; i < _size ; i++ )
					this->_tab[i] = copy._tab[i];
			}
			return *this;
		}
		//Methode
		size_t	size() const { return ( this->_size ); }
    
	private:
		//Attributes
		T		*_tab;
		size_t	_size;

};

#endif
