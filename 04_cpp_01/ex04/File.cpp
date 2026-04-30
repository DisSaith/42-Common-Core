/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:02:45 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/09 15:02:53 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(void)
{
	return ;
}

File::~File(void)
{
	_filecopy.close();
	_fileread.close();
}

void	File::initialisation(std::string const& filename,
							std::string const& s1, 
							std::string const& s2)
{
	_filename = filename;
	_filename_copy = filename + ".replace";
	_s1 = s1;
	_s2 = s2;
	_fileread.open(_filename.c_str());
	_filecopy.open(_filename_copy.c_str());
}

bool	File::check_parameters(char **av)
{
	std::string		parameter;
	std::ifstream	infile;
	int				i = 1;
	
	while (av[i])
	{
		parameter = av[i];
		if (parameter.empty() == true)
		{
			std::cerr << "error: empty parameter" << std::endl;
			return (false);
		}
		i++;
	}

	infile.open(av[1]);
	if (infile.good() != true)
	{
		infile.close();
		std::cerr << "error: open file" << std::endl;
		return (false);
	}
	infile.close();
	return (true);
}

bool	File::check_occurencies(std::string const& line,
								std::string const& s1)
{
	unsigned long	j = 0;
	
	while (s1[j] && s1[j] == line[j])
		j++;
	if (j == s1.length())
		return (true);
	return (false);
}

void	File::replace(std::string &line,
						std::string const& s1,
						std::string const& s2)
{
	unsigned long	i = 0;

	while (line[i])
	{
		if (line[i] == s1[0])
		{
			if (File::check_occurencies(&line[i], s1) == true)
			{
				line.erase(i, s1.length());
				line.insert(i, s2);
				i += s2.length();
			}
		}
		else
			i++;
	}
}

void	File::copy_and_replace(void)
{
	std::string		line;

	while (true)
	{
		if (getline(_fileread, line) == false)
			break ;
		File::replace(line, _s1, _s2);
		_filecopy << line << std::endl;
	}
}
