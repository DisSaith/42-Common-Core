/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:49:25 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/12 14:02:09 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//Destructor
BitcoinExchange::~BitcoinExchange() {}

//Default contructor
BitcoinExchange::BitcoinExchange() : _dataBase(), _infile()
{
	std::ifstream	dataBase("data.csv");
	std::string		line;
	std::string		date;
	std::string		price;

	if ( dataBase.good() == true )
	{
		while( getline( dataBase, line ) )
		{
			date = line.substr(0, line.find(","));
			price = line.substr(line.find(",") + 1);
			_dataBase[date] = std::atof(price.c_str());
		}
		dataBase.close();
	}
	else
	{
		dataBase.close();
		throw std::invalid_argument("cant't open data.csv.");
	}
}

//Private copy contructor
BitcoinExchange::BitcoinExchange( BitcoinExchange const& copy ) { (void)copy; }

//Private Overload operator=
BitcoinExchange& BitcoinExchange::operator=( BitcoinExchange const& copy ) 
{ (void)copy; return *this; }

//Methods
void	BitcoinExchange::openFile( char *argv )
{
	_infile.open( argv );

	if ( _infile.good() == true )
	{
		parseFile();
	}
	else
	{
		_infile.close();
		throw std::invalid_argument("could not open file.");
	}
}

void	BitcoinExchange::parseFile()
{
	std::string		line;
	
	while ( getline( _infile, line ) )
	{
		try
		{
			if ( validateLine( line ) == true )
			{
				std::string	date = line.substr(0, line.find(" "));
				std::string	value = line.substr(line.find("|") + 2);
				displayResult( date, value );
			}
		}
		catch( std::exception & e )
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

bool	BitcoinExchange::validateLine( std::string & line )
{
	std::string	date;
	long long	year;
	long long	month;
	long long	day;
	double		value;
	size_t		date_length;

	if ( line == "date | value" )
		return ( false );
	if ( line.length() < 13 )
		throw	BitcoinExchange::BadInput( line );
	if ( line[4] != '-' || line[7] != '-' || line[11] != '|'
		|| line[10] != ' ' || line[12] != ' ' )
		throw	BitcoinExchange::BadInput( line );
	
	date = line.substr(0, line.find("|"));
	date_length = date.length();
	if ( date_length < 11 || date_length > 11 )
		throw	BitcoinExchange::BadInput( line );
	for (size_t i = 0 ; i < date_length - 1 ; i++)
	{
		if ( i == 4 || i == 7 )
			continue ;
		if ( date[i] && !std::isdigit(date[i]) )
			throw	BitcoinExchange::BadInput( line );
	}

	year = static_cast <long long>( std::atof( line.substr(0, 4).c_str() ) );
	month = static_cast <long long>( std::atof( line.substr(5, 2).c_str() ) );
	day = static_cast <long long>( std::atof( line.substr(8, 2).c_str() ) );
	value = std::atof( line.substr(13).c_str() );

	if ( year < 2009 || year > 2026 )
		throw	BitcoinExchange::BadInput( line );
	if ( month < 1 || month > 12 )
		throw	BitcoinExchange::BadInput( line );
	if ( day < 1 || day > 31 )
		throw	BitcoinExchange::BadInput( line );
	if ( value < 0 )
		throw	std::out_of_range("not a positive number.");
	if ( value > 1000 )
		throw	std::out_of_range("too large a number.");
	if ( checkDate( day, month, year ) == false )
		throw	BitcoinExchange::BadInput( line );

	return ( true );
}

bool	BitcoinExchange::checkDate( int const& day,
									int const& month,
									int const& year ) const
{
	int		daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 30, 31};
	bool	isLeapYear = ( year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0);
	//Leap year if :
	// - Divisible by 4 AND not divisible by 100
	// - OR divisible by 400

	if ( isLeapYear && month == 2 )
		daysPerMonth[2] = 29;

	if ( day > daysPerMonth[month] )
		return ( false );
	return ( true );
}

void	BitcoinExchange::displayResult( std::string const& date, std::string const& value )
{
	double									double_value;
	std::map<std::string, double>::iterator	it;

	double_value = std::atof( value.c_str() );
	it = _dataBase.lower_bound(date);

	if (it == _dataBase.end() || it->first != date)
    {
        if (it == _dataBase.begin())
            throw std::logic_error("no earlier date available.");
        --it;
    }
	std::cout << date << " => " << double_value << " = "
				<<  double_value * it->second <<std::endl;
}

//Nested class exception
BitcoinExchange::BadInput::BadInput() throw() : std::exception(), _error() {}

BitcoinExchange::BadInput::~BadInput() throw() {}

BitcoinExchange::BadInput::BadInput( std::string const& line )
	: std::exception(), _error( "bad input => " + line ) {}

const char* BitcoinExchange::BadInput::what() const throw()
{
	return ( _error.c_str() ); 
}
