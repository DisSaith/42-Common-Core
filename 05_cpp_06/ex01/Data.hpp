/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 09:54:37 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/03 09:54:38 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{
    public:
        Data();
        Data( int const& id, double const& value, std::string const& name );
        ~Data();

		//Getters
		int				getId() const;
		double			getValue() const;
		std::string		getName() const;
            
	private:
		//Attributs
		std::string	_name;
		double		_value;
		int			_id;

		Data( Data const& copy );
		Data& operator=( Data const& copy );
};

std::ostream&	operator<<( std::ostream & out, Data const& object );

#endif
