/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:49:12 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/12 14:02:34 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <algorithm>
# include <fstream>
# include <exception>
# include <cstdlib>
# include <cctype>

class BitcoinExchange
{
    public:
        ~BitcoinExchange(); //Destructor
        BitcoinExchange(); //Constructor
     
		//Methods
		void	openFile( char *argv );
		void	parseFile();
		bool	validateLine( std::string & line );
		bool	checkDate( int const& day, int const& month, int const& year ) const;
		void	displayResult( std::string const& date, std::string const& value );

		//Nested class exception
		class BadInput : public std::exception
		{
			public:
				BadInput( std::string const& line ); //Constructor
				virtual ~BadInput() throw(); //Destructor
				virtual const char* what() const throw(); //virtual what() methode
			private:
				BadInput() throw(); //Private default constructor
				std::string		_error; //Attribute
		};

    private:
		BitcoinExchange( BitcoinExchange const& copy ); //Private
		BitcoinExchange& operator=( BitcoinExchange const& copy ); //Private

		//Attributes
		std::map<std::string, double>	_dataBase;
		std::ifstream					_infile;
};

#endif
