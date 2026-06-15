/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 09:55:45 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/03 09:55:46 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"

int	main( void )
{
	Base	*ptr1 = generate();
	std::cout << "identify ( Base * p ) -> ";
	identify( ptr1 );
	std::cout << "identify ( Base & p ) -> ";
	identify( *ptr1 );
	delete ptr1;
	return (0);
}
