/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 10:44:59 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/09 15:01:57 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include <fstream>
#include <iostream>

class	File
{

	private:
		std::string		_filename;
		std::string		_filename_copy;
		std::string		_s1;
		std::string		_s2;
		std::ifstream	_fileread;
		std::ofstream	_filecopy;

	public:
		File(void);
		~File(void);

		void	initialisation(std::string const& filename,
								std::string const& s1,
								std::string const& s2);
		void	copy_and_replace(void);

		static bool		check_parameters(char **av);
		static bool		check_occurencies(std::string const& line,
											std::string const& s1);
		static void		replace(std::string &line,
								std::string const& s1,
								std::string const& s2);
};

#endif
