/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 17:33:52 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/03 17:33:54 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <sstream>
#include <iostream>

class Contact
{

	private:
		std::string	string_index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
		int			index;

	public:
		Contact(void);
		~Contact(void);

		static std::string	into_string(int const& integer);
		std::string 		modify_input(std::string const& input) const;
		bool				wrong_input(std::string const& field, std::string const& situation) const;
		void				create_new_contact(Contact &contact, int const& index, int const& max_contacts);
		void				decrease_index(void);
		void				display_fields(void) const;
		void				search_display(void) const;

};

#endif
