/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:00:08 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/09 11:08:15 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <deque>
# include <stack>

template < typename T >
class MutantStack : public std::stack<T> // Héritage de stack
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack( MutantStack const& copy ) : std::stack<T>(copy) {}
        virtual ~MutantStack() {}
        MutantStack& operator=( MutantStack const& copy ) 
		{
            if (this != &copy) std::stack<T>::operator=(copy);
            return (*this);
        }

        // On utilise l'it de la struc interne protected 'c' de std::stack
        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin() { return (this->c.begin()); }
        iterator end() { return (this->c.end()); }
};

template < typename T >
class MutantStack_bis
{
    public:
        ~MutantStack_bis() {} //Destructor
		
		//Constructors
        MutantStack_bis() : _tab() {}
        MutantStack_bis( MutantStack_bis const& copy ) : _tab( copy._tab ) {}
        
		//Operator overload=
		MutantStack_bis& operator=( MutantStack_bis const& copy )
		{ 
			if ( this != &copy )
				this->_tab = copy._tab;
			return (*this); 
		}

		//Nested iterator
		class iterator
		{
			public:
				//Constructors
				iterator() {};
				iterator( typename std::deque<T>::iterator it ) : _it( it ) {}
				
				//Operators overloads
				iterator&	operator=( iterator const& copy ) 
				{ _it = copy._it; return *this; }
				
				T&			operator*() { return ( *_it ); }
				iterator&	operator++() { _it++; return *this; }
				iterator&	operator--() { _it--; return *this; }
				
				bool		operator!=( iterator const& b )
				{ return ( this->_it != b._it ); }
				
				bool		operator==( iterator const& b )
				{ return ( this->_it == b._it ); }

			private:
				typename std::deque<T>::iterator	_it; //Attribute
		};

		//Methodes
		size_t		size() const { return ( _tab.size() ); }
		bool		empty() const { return ( _tab.size() == 0 ); }
		void		push( T const& element ) { _tab.push_front( element ); }
		void		pop() { _tab.pop_front(); }
		T&			top() { return ( _tab.front() ); }
		iterator	begin() { return iterator( _tab.begin() );  }
		iterator	end() { return iterator( _tab.end() ); }

    private:
		std::deque<T>	_tab; //Attribute
};

#endif
