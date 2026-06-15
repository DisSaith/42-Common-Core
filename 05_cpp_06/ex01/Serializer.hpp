/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 09:54:54 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/03 09:56:47 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
    public:
		static uintptr_t	serialize( Data* ptr );
		static Data*		deserialize( uintptr_t raw );

	private:
		Serializer();
        Serializer( Serializer const& copy );
        ~Serializer();
		Serializer& operator=( Serializer const& copy );
};

#endif
