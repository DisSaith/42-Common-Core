/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:19:39 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/17 13:44:09 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const	Fixed::_fract_bits = 8;

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const& copy)
{
	std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(int const integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = integer << this->_fract_bits;
}

Fixed::Fixed(float const floater)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(floater * 256);
}

Fixed&			Fixed::operator=(Fixed const& copy)
{
	std::cout << "Copy assignement operator called" << std::endl;
    if (this != &copy)
    {
		this->_value = copy.getRawBits();
    }
    return *this;
}

int				Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void			Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float			Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)256);
}

int				Fixed::toInt(void) const
{
	return (this->_value >> this->_fract_bits);
}

std::ostream&	operator<<(std::ostream & flux, Fixed const& fixed)
{
	flux << fixed.toFloat();
	return flux;
}
