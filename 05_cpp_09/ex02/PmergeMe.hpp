/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:32:07 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/12 13:46:56 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <list>
# include <deque>
# include <vector>
# include <algorithm>
# include <exception>
# include <limits>
# include <ctime>

class PmergeMe
{
    public:
		~PmergeMe(); //Destructor
		PmergeMe(); //Default constructor

		//Methods
		void	checkArguments( char **av );
		void	sorting();

		//Ford-Johnson sorting
		void    binaryInsertVector( std::vector<int>& chain, int val, size_t bound );
		void	fordJohnsonVector( std::vector<int> & seq );
		void	fordJohnsonDeque( std::deque<int>& seq );
		void	binaryInsertDeque( std::deque<int>& chain, int val, size_t end );

    private:
        PmergeMe( PmergeMe const& copy ); //Private copy constructor
		PmergeMe& operator=( PmergeMe const& copy ); //Private overload operator=
        
		//Attributes
		std::vector<int>	_vector;
		std::deque<int>		_deque;
};

#endif
