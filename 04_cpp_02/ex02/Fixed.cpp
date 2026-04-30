/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:19:39 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/21 10:13:20 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const	Fixed::_fract_bits = 8;

Fixed::Fixed() : _value(0)
{
	return ;
}

Fixed::~Fixed()
{
	return ;
}

Fixed::Fixed(Fixed const& copy)
{
    *this = copy;
}

Fixed::Fixed(int const integer)
{
	this->_value = integer << this->_fract_bits;
}

Fixed::Fixed(float const floater)
{
	this->_value = roundf(floater * 256);
}

Fixed&			Fixed::operator=(Fixed const& copy)
{
    if (this != &copy)
    {
		this->_value = copy.getRawBits();
    }
    return *this;
}

Fixed&			Fixed::operator++(void)
{
	_value++;
    return *this;
}

Fixed			Fixed::operator++(int)
{
	Fixed	result(*this);
	this->_value++;
    return result;
}

Fixed&			Fixed::operator--(void)
{
	_value--;
    return *this;
}

Fixed			Fixed::operator--(int)
{
	Fixed	result(*this);
	this->_value--;
    return result;
}

int				Fixed::getRawBits(void) const
{
	return (this->_value);
}

void			Fixed::setRawBits(int const raw)
{
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

Fixed&			Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed const&	Fixed::min(Fixed const& a, Fixed const& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed&			Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed const&	Fixed::max(Fixed const& a, Fixed const& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

std::ostream&	operator<<(std::ostream & flux, Fixed const& fixed)
{
	flux << fixed.toFloat();
	return flux;
}

bool			operator==(Fixed const& a, Fixed const& b)
{
	if (a.getRawBits() == b.getRawBits())
		return (true);
	else
		return (false);
}

bool			operator!=(Fixed const& a, Fixed const& b)
{
	if (a.getRawBits() != b.getRawBits())
		return (true);
	else
		return (false);
}

bool			operator>(Fixed const& a, Fixed const& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (true);
	else
		return (false);
}

bool			operator>=(Fixed const& a, Fixed const& b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (true);
	else
		return (false);
}

bool			operator<(Fixed const& a, Fixed const& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (true);
	else
		return (false);
}

bool			operator<=(Fixed const& a, Fixed const& b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (true);
	else
		return (false);
}

Fixed			operator+(Fixed const& a, Fixed const& b)
{
	Fixed	result;

	result.setRawBits(a.getRawBits() + b.getRawBits());

	return (result);
}

Fixed			operator-(Fixed const& a, Fixed const& b)
{
	Fixed	result;

	result.setRawBits(a.getRawBits() - b.getRawBits());

	return (result);
}

Fixed			operator*(Fixed const& a, Fixed const& b)
{
	Fixed	result;
	long long res = (long long)a.getRawBits() * b.getRawBits();
	result.setRawBits((int)(res >> 8));

	return (result);
}

Fixed			operator/(Fixed const& a, Fixed const& b)
{
	Fixed	result;
	
	result.setRawBits((a.getRawBits() << 8) / b.getRawBits());

	return (result);
}
