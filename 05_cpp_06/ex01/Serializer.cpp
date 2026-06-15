/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 09:54:49 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/03 09:54:52 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer( Serializer const& copy ) { *this = copy; }

Serializer& Serializer::operator=( Serializer const& copy )
{
	(void)copy;
    return *this;
}

uintptr_t   Serializer::serialize( Data* ptr )
{
	return ( reinterpret_cast<uintptr_t>( ptr ) );
}

Data*       Serializer::deserialize( uintptr_t raw )
{
	return ( reinterpret_cast<Data*>( raw ) );
}
