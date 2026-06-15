/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:56:26 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/12 14:00:51 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <algorithm>
# include <exception>

class RPN
{
    public:
		~RPN(); //Destructor
		RPN(); //Default constructor

		//Methods
		void		checkArgument( char *av );
		void		doOperations( char *av );

    private:
        RPN( RPN const& copy ); //Private copy constructor
		RPN& operator=( RPN const& copy ); //Private overload operator=
		
		//Attribute
		std::stack<int>		_numbers;
};

#endif
