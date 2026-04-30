/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:19:33 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/17 16:07:47 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    public:
        Fixed();
        ~Fixed();
        Fixed(Fixed const& copy);
		Fixed(int const integer);
		Fixed(float const floater);

		Fixed&	operator=(Fixed const& copy);
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		void	setRawBits(int const raw);
		int		getRawBits(void) const;

		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed&			min(Fixed & a, Fixed & b);
		static Fixed const&		min(Fixed const& a, Fixed const& b);
		static Fixed&			max(Fixed & a, Fixed & b);
		static Fixed const&		max(Fixed const& a, Fixed const& b);


    private:
		int					_value;
		static const int	_fract_bits;
};

std::ostream&	operator<<(std::ostream & flux, Fixed const& fixed);

bool			operator==(Fixed const& a, Fixed const& b);
bool			operator!=(Fixed const& a, Fixed const& b);
bool			operator>(Fixed const& a, Fixed const& b);
bool			operator>=(Fixed const& a, Fixed const& b);
bool			operator<(Fixed const& a, Fixed const& b);
bool			operator<=(Fixed const& a, Fixed const& b);

Fixed			operator+(Fixed const& a, Fixed const& b);
Fixed			operator-(Fixed const& a, Fixed const& b);
Fixed			operator*(Fixed const& a, Fixed const& b);
Fixed			operator/(Fixed const& a, Fixed const& b);

#endif
