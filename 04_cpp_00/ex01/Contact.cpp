/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 17:33:47 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/03 17:33:49 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return;
}

std::string	Contact::into_string(int const& integer)
{
	std::ostringstream	a;
	a << integer;
	return a.str();
}

std::string 	Contact::modify_input(std::string const& input) const
{
	std::string	output = input;
	int const size_max = 10;
	int size_input = input.length();

	if (size_input < size_max)
		output = std::string(10 - output.length(), ' ') + output;
	else if (size_input > size_max)
	{
		output.erase(output.begin()+9, output.end());
		output += ".";
	}
	return (output);
}

bool	Contact::wrong_input(std::string const& field, std::string const& situation) const
{
	int i = 0;

	if (field.empty() == true || field[0] == '\n')
		return (true);
	while (field[i])
	{
		if (situation == "string" && (!std::isalpha(field[i]) && field[i] != '-'))
		{
			std::cout << "Only letters and hyphens are allowed for this field." << std::endl;
			return (true);
		}
		else if (situation == "sentance" && (!std::isalpha(field[i]) && field[i] != ' '))
		{
			std::cout << "Only letters and spaces are allowed for this field." << std::endl;
			return (true);
		}
		else if (situation == "digit" && !std::isdigit(field[i]))
		{
			std::cout << "Only digits are allowed for this field." << std::endl;
			return (true);
		}
		i++;
	}
	return (false);
}

void Contact::create_new_contact(Contact &contact, int const& index, int const& max_contacts)
{
	if (index < max_contacts)
	{
		contact.index = index;
		contact.string_index = into_string(contact.index);
	}
	else
	{
		contact.index = max_contacts - 1;
		contact.string_index = into_string(contact.index);
	}
	std::cout << "Please enter the following informations :" << std::endl;
	while (wrong_input(contact.first_name, "string") == true)
	{
		std::cout << "New contact first name :" << std::endl;
		getline(std::cin, contact.first_name);
	}
	while (wrong_input(contact.last_name, "string") == true)
	{
		std::cout << "New contact last name :" << std::endl;
		getline(std::cin, contact.last_name);
	}
	while (wrong_input(contact.nickname, "string") == true)
	{
		std::cout << "New contact nickname :" << std::endl;
		getline(std::cin, contact.nickname);
	}
	while (wrong_input(contact.phone_number, "digit") == true)
	{
		std::cout << "New contact phone number :" << std::endl;
		getline(std::cin, contact.phone_number);
	}
	while (wrong_input(contact.darkest_secret, "sentance") == true)
	{
		std::cout << "New contact darkest secret :" << std::endl;
		getline(std::cin, contact.darkest_secret);
	}
	return;
}

void	Contact::decrease_index(void)
{
	index--;
	string_index = into_string(index);
}

void 	Contact::search_display(void) const
{
	std::cout 	<< "|" << modify_input(string_index)
				<< "|" << modify_input(first_name)
				<< "|" << modify_input(last_name)
				<< "|" << modify_input(nickname) << "|" << std::endl;
}

void	Contact::display_fields(void) const
{
	std::cout 	<< "First name: " << first_name << std::endl
				<< "Last name: " << last_name << std::endl
				<< "Nickname: " << nickname << std::endl
				<< "Phone number: " << phone_number << std::endl
				<< "Darkest secret: " << darkest_secret << std::endl;
}

Contact::~Contact(void)
{
	return;
}