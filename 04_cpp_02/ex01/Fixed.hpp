/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:19:33 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/17 12:02:43 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
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
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

    private:
		int					_value;
		static const int	_fract_bits;
};

std::ostream& operator<<(std::ostream & flux, Fixed const& fixed);

#endif
