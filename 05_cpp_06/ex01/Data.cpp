/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 09:54:33 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/03 09:54:34 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _name( "default" ), _value( 0.0 ), _id( 0 ) {}

Data::Data( int const& id, double const& value, std::string const& name )
	: _name( name ), _value( value ), _id( id ) {}

Data::~Data() {}

Data::Data( Data const& copy )
{
    *this = copy;
}

Data& Data::operator=( Data const& copy )
{
    if (this != &copy)
    {
		this->_name = copy._name;
		this->_value = copy._value;
		this->_id = copy._id;
    }
    return *this;
}

int             Data::getId() const
{
	return ( this->_id );
}

double          Data::getValue() const
{
	return ( this->_value );
}

std::string     Data::getName() const
{
	return ( this->_name );
}

std::ostream&    operator<<( std::ostream & out, Data const& object )
{
	out << "Id: " << object.getId() << std::endl
		<< "Name: " << object.getName() << std::endl
		<< "Value: " << object.getValue() << std::endl;
	return ( out );
}
