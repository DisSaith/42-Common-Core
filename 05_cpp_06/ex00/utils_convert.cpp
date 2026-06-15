/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_convert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:06:28 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/01 17:52:29 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool		isPseudoLiteral( std::string const& str )
{
	std::string		pseudoLiteral[6] = {
		"+inf", "-inf", "nan", "+inff", "-inff", "nanf"};
	size_t i = 0;
	
	while ( i < 6 )
	{
		if ( str == pseudoLiteral[i] )
			return ( true );
		i++;
	}
	return ( false );
}

std::string	isLiteralValid( std::string const& literal )
{
	int	haveChar = 0;
	int	haveDot = 0;
	int	haveF = 0;
	int	haveSign = 0;
	int	haveDigit = 0;

	if ( literal.empty() == true )
		return ( "false" );
	if ( isPseudoLiteral( literal ) == true )
		return ( "pseudoLiteral" );
	if ( literal.length() == 1 && !std::isdigit( literal[0] ) )
		return ( "char" );
	for (size_t i = 0 ; i < literal.size() ; i++)
	{
		if ( !std::isdigit( literal[i] )
				&& literal[i] != '-'
				&& literal[i] != 'f'
				&& literal[i] != '.'
				&& literal[i] != '+' )
			haveChar++;
		else if ( literal[i] == '.' )
			haveDot++;
		else if ( literal[i] == 'f' )
			haveF++;
		else if ( literal[i] == '-' || literal[i] == '+')
			haveSign++;
		else if ( std::isdigit( literal[i] ) )
			haveDigit++;
	}
	if ( haveDot > 1 || haveChar > 1 
		|| haveF > 1 || haveSign > 1
		|| (haveSign == 1 && literal[0] != '-' && literal[0] != '+' )
		|| !haveDigit )
		return ( "false" );
	else if ( !haveDot && !haveF && !haveChar )
		return ( "int" );
	else if ( haveDot && haveF && !haveChar && literal[literal.length() - 1] == 'f')
		return ( "float" );
	else if ( haveDot && !haveF && !haveChar )
		return ( "double" );
	return ( "false" );
}

void		displayConvert( std::string const& char_, std::string const& integer_,
						float const& float_, double const& double_,
						bool const& floatOverflow, bool const& doubleOverflow )
{
	std::cout << "char: " << char_ << std::endl
			<< "int: " << integer_ << std::endl;
	if ( floatOverflow == true )
		std::cout << "float: impossible" << std::endl;
	else 
		std::cout << "float: " << std::fixed << std::setprecision(1) << float_ 
			<< "f" << std::endl;
	if ( doubleOverflow == true )
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << double_ << std::endl;
}

std::string	char_to_string( char const& character )
{
	std::string string_(1, character);
	return ( string_ );
}

char		string_to_char( std::string const& str )
{
	char char_ = static_cast<char>(str[0]);
	return ( char_ );
}

std::string my_to_string(int const& value) 
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

std::string my_to_string(float const& value) 
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

std::string my_to_string(double const& value) 
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

double		my_stod( std::string const& literal )
{
	double				double_ = 0.0;
	std::stringstream	ss;
	ss << literal;
	ss >> double_;
	return ( double_ );
}

long double	my_stold( std::string const& literal )
{
	long double			long_double_ = 0.0;
	std::stringstream	ss;
	ss << literal;
	ss >> long_double_;
	return ( long_double_ );
}

float		my_stof( std::string const& literal )
{
	float				float_ = 0.0f;
	std::stringstream	ss;
	ss << literal;
	ss >> float_;
	return ( float_ );
}
