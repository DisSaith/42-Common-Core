/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 17:34:08 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/08 12:02:21 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : nbr_contacts(0), max_contacts(MAX_CONTACTS)
{
	std::cout << "Welcome into your PhoneBook !" << std::endl;
	return;
}

bool PhoneBook::check_search_index(std::string const& string_index,
									int const& nbr_contacts,
									int const& max_contacts) const
{
	int int_index;

	if (string_index.length() > 1 
		|| string_index.empty() == true
		|| std::isdigit(string_index[0]) == false)
		return (false);
	int_index = atoi(string_index.c_str());
	if (int_index >= nbr_contacts 
		|| int_index >= max_contacts 
		|| int_index < 0)
		return (false);
	return (true);
}

void PhoneBook::display_menu(void) const
{
	std::cout << "Which action would you like to do ?" << std::endl
		<< "ADD, SEARCH or EXIT" << std::endl;
	return;
}

void PhoneBook::add_a_contact(PhoneBook &phonebook)
{
	Contact new_contact;
	
	std::cout << "You have currently " << phonebook.nbr_contacts << " contacts." << std::endl;
	if (phonebook.nbr_contacts == phonebook.max_contacts)
		std::cout << "Your PhoneBook is full, the oldest contact will be deleted." << std::endl;
	new_contact.create_new_contact(new_contact, phonebook.nbr_contacts, phonebook.max_contacts);
	if (phonebook.nbr_contacts < phonebook.max_contacts)
	{
		phonebook.contacts[phonebook.nbr_contacts] = new_contact;
		phonebook.nbr_contacts++;
	}
	else
	{
		phonebook.del_oldest_contact(phonebook);
		phonebook.contacts[phonebook.max_contacts - 1] = new_contact;
	}
	return;
}

void PhoneBook::del_oldest_contact(PhoneBook &phonebook)
{
	int	i = 0;

	while (i < phonebook.max_contacts - 1)
	{
		phonebook.contacts[i] = phonebook.contacts[i + 1];
		phonebook.contacts[i].decrease_index();
		i++;
	}
}

void PhoneBook::search_a_contact(PhoneBook const& phonebook) const
{
	std::string string_index;
	int i = 0;

	if (phonebook.nbr_contacts == 0)
	{
		std::cout << "You've no contacts yet. Please add contacts before." << std::endl;
		return ;
	}
	while (i < phonebook.nbr_contacts)
	{
		phonebook.contacts[i].search_display();
		i++;
	}
	std::cout << "Which contact, between index [0] and ["
		<< phonebook.nbr_contacts - 1 << "], want you to display ?" << std::endl;
	getline(std::cin, string_index);
	while (!check_search_index(string_index, phonebook.nbr_contacts, phonebook.max_contacts))
	{
		std::cout << "Invalid index, try again :" << std::endl;
		getline(std::cin, string_index);
	}
	phonebook.contacts[atoi(string_index.c_str())].display_fields();
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Closing of the PhoneBook, see you soon !" << std::endl;
	return;
}
