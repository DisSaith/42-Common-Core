/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:51:38 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/01 17:15:07 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <cctype>
# include <cstdlib>
# include <cfloat>
# include <climits>

//Externals functions
bool			isPseudoLiteral( std::string const& literal );
std::string		isLiteralValid( std::string const& literal );
std::string		char_to_string( char const& character );
char			string_to_char( std::string const& str );
std::string		my_to_string( int const& value );
std::string		my_to_string( float const& value );
std::string		my_to_string( double const& value );
float			my_stof( std::string const& literal );
double			my_stod( std::string const& literal );
long double		my_stold( std::string const& literal );
void			convertPseudoLiteral( std::string const& str );
void			convertChar( std::string const& literal );
void			convertInt( std::string const& literal );
void			convertFloat( std::string const& literal );
void			convertDouble( std::string const& literal );
void			displayConvert( std::string const& char_, 
								std::string const& integer_,
								float const& float_,
								double const& double_,
								bool const& floatOverflow,
								bool const& doubleOverflow );

//Class not instantiable
class ScalarConverter
{
    public:
		static void		convert( std::string const& literal );

    private:
		ScalarConverter(); //Default Constructor
        ~ScalarConverter(); //Destructor
        ScalarConverter( ScalarConverter const& copy ); //Copy Constructor
		ScalarConverter& operator=( ScalarConverter const& copy ); //Overload operator=
};

#endif
