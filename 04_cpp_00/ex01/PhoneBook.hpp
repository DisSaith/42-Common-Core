/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 17:34:17 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/08 12:01:59 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <cctype>
#include <string>
#include <cmath>

# define MAX_CONTACTS 8

class PhoneBook
{
	private:		
		Contact		contacts[MAX_CONTACTS];
		int			nbr_contacts;
		int const	max_contacts;

	public:		
		PhoneBook(void);
		~PhoneBook(void);
		
		bool 		check_search_index(std::string const& string_index,
										int const& nbr_contacts,
										int const& max_contacts) const;
		
		void 		display_menu(void) const;
		void 		add_a_contact(PhoneBook &phonebook);
		void 		del_oldest_contact(PhoneBook &phonebook);
		void 		search_a_contact(PhoneBook const& phonebook) const;
};

#endif
