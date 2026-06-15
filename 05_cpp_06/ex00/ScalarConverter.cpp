/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:06:28 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/01 18:06:04 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter( ScalarConverter const& copy ) {(void)copy;}

ScalarConverter& ScalarConverter::operator=( ScalarConverter const& copy )
{
	(void)copy;
	return (*this);
}

void	convertChar( std::string const& literal )
{
	std::string	charStr;
	std::string	intStr;
	char		char_;
	
	char_ = string_to_char( literal );
	charStr = "\'" + literal + "\'";
	intStr = my_to_string( static_cast<int>( char_ ) );
	displayConvert( charStr, intStr,
					static_cast<float>( char_ ), static_cast<double>( char_ ),
					false, false );
}

//Old convert functions
/*void	convertInt( std::string const& literal )
{
	std::string	charStr = "Non displayable";
	std::string	intStr = "impossible";
	long double integer_ = my_stold( literal.c_str() );
	bool		floatOverflow = true;
	bool		doubleOverflow = true;
	
	if ( integer_ >= 32.0 && integer_ <= 126.0 )
		charStr = "\'" + char_to_string( static_cast<char>( integer_ ) ) + "\'";
	else if ( integer_ > 127.0 || integer_ < 0.0 )	
		charStr = "impossible";
	if ( integer_ <= 2147483647.0 && integer_ >= -2147483648.0)
		intStr = my_to_string( static_cast<int>( integer_ ) );
	if ( integer_ <= FLT_MAX && integer_ >= -FLT_MAX )
		floatOverflow = false;
	if ( integer_ <= DBL_MAX && integer_ >= -DBL_MAX )
		doubleOverflow = false;
	displayConvert( charStr, intStr,
					static_cast<float>( integer_ ), static_cast<double>( integer_ ),
					floatOverflow, doubleOverflow );
}

void	convertFloat( std::string const& literal )
{
	std::string		charStr = "Non displayable";
	std::string		intStr = "impossible";
	long double		float_ = my_stold( literal );
	bool			floatOverflow = true;
	bool			doubleOverflow = true;
	
	if ( float_ >= 32.0f && float_ <= 126.0f )
		charStr = "\'" + char_to_string( static_cast<char>( float_ ) ) + "\'";
	else if ( float_ > 127.0f || float_ < 0.0f )
		charStr = "impossible";
	if ( float_ <= 2147483647.0f && float_ >= -2147483648.0f)
		intStr = my_to_string( static_cast<int>( float_ ) );
	if ( float_ <= FLT_MAX && float_ >= -FLT_MAX )
		floatOverflow = false;
	if ( float_ <= DBL_MAX && float_ >= -DBL_MAX )
		doubleOverflow = false;
	displayConvert( charStr, intStr,
					static_cast<float>( float_ ), static_cast<double>(float_ ),
					floatOverflow, doubleOverflow);

}

void	convertDouble( std::string const& literal )
{
	std::string		charStr = "Non displayable";
	std::string		intStr = "impossible";
	long double		double_ = my_stold( literal );
	bool			floatOverflow = true;
	bool			doubleOverflow = true;
	
	if ( double_ >= 32.0 && double_ <= 126.0 )
		charStr = "\'" + char_to_string( static_cast<char>( double_ ) ) + "\'";
	else if ( double_ > 127.0 || double_ < 0.0 )
		charStr = "impossible";
	if ( double_ <= 2147483647.0 && double_ >= -2147483648.0)
		intStr = my_to_string( static_cast<int>( double_ ) );
	if ( double_ <= FLT_MAX && double_ >= -FLT_MAX )
		floatOverflow = false;
	if ( double_ <= DBL_MAX && double_ >= -DBL_MAX )
		doubleOverflow = false;
	displayConvert( charStr, intStr,
					static_cast<float>( double_ ), static_cast<double>( double_ ),
					floatOverflow, doubleOverflow);
}*/

void	convertPseudoLiteral( std::string const& str )
{
	std::string	floatStr = "";
	std::string	doubleStr = "";
	if ( str == "nanf" || str == "+inff" || str == "-inff")
	{
		floatStr = str;
		doubleStr = str.substr(0, (str.length() - 1));
	}
	else
	{
		floatStr = str + "f";
		doubleStr = str;
	}
	std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: " << floatStr << std::endl
			<< "double: " << doubleStr << std::endl;
}

void	converting( std::string const& literal )
{
	std::string		charStr = "Non displayable";
	std::string		intStr = "impossible";
	long double		value = my_stold( literal );
	/* [IF PROBLEMS WITH my_stold]*/
	//double			value = std::strtod( literal.c_str(), NULL );
	bool			floatOverflow = true;
	bool			doubleOverflow = true;
	
	if ( value >= 32.0 && value <= 126.0 )
		charStr = "\'" + char_to_string( static_cast<char>( value ) ) + "\'";
	else if ( value > 127.0 || value < 0.0 )
		charStr = "impossible";
	if ( value <= 2147483647.0 && value >= -2147483648.0)
		intStr = my_to_string( static_cast<int>( value ) );
	if ( value <= FLT_MAX && value >= -FLT_MAX )
		floatOverflow = false;
	if ( value <= DBL_MAX && value >= -DBL_MAX )
		doubleOverflow = false;
	displayConvert( charStr, intStr,
					static_cast<float>( value ), static_cast<double>( value ),
					floatOverflow, doubleOverflow);
}

void	ScalarConverter::convert( std::string const& literal )
{
	std::string	isLiteral;

	isLiteral = isLiteralValid( literal );
	if ( isLiteral == "false" )
		std::cout << "Error: invalide literal argument." << std::endl;
	else if ( isLiteral == "pseudoLiteral" )
		convertPseudoLiteral( literal );
	else if ( isLiteral == "char" )
		convertChar( literal );
	else
	{
		if ( isLiteral == "float" )
			converting( literal.substr(0, literal.length() - 1) );
		else
			converting( literal );
	}
}
