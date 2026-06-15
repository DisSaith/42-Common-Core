/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:47:02 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/08 15:49:59 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <deque>
# include <algorithm>
# include <limits>

class Span
{
    public:
        ~Span(); // Destructor
        
		//Constructors
		Span( unsigned int const& N );
        Span( Span const& copy );
        
		//Overload operator=
		Span& operator=( Span const& copy );

		//Methodes
		void				addNumber( int const& number );
		unsigned long long	shortestSpan() const;
		unsigned long long	longestSpan() const;

		//Template methode to add N numbers
		template < typename Iterator >
		void				addNNumbers( Iterator begin, Iterator end )
		{
			while( begin != end )
			{
				if ( _tab.size() >= this->_max_size )
					throw std::out_of_range("tab reaches already is max size");
				
				addNumber(*begin);
				begin++;
			}
		}

    private:
        Span(); //Private default constructor

		//Attributes
		unsigned int	_max_size;
		std::deque<int>	_tab;

};

#endif
