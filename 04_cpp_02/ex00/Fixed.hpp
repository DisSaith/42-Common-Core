/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:19:33 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/17 12:03:52 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
    public:
        Fixed();
        Fixed(Fixed const& copy);
        ~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
        
		Fixed& operator=(Fixed const& copy);

    private:
		int					_value;
		static const int	_fract_bits;
};

#endif
