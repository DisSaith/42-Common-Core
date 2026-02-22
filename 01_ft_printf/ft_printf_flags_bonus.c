/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:45:46 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/04 13:45:51 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_flag *flags)
{
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
}

/*int		ft_parsing_width(t_flag *flags, const char *str, int *i)
{
	int		width;

	width = 0;
	if (str[*i] == '-')
		flags->minus = 1;
	if (str[*i] == '0')
		flags->zero = 1;
	if (str[*i] == '.')
		flags->dot = 1;
	(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
			width *= 10;
			width += str[*i] - 48;
			(*i)++;
	}
	return (width);
}*/

int	ft_flag_parsing(va_list *args, const char *str, int *i)
{
	t_flag	flags;

	init_struct(&flags);
	while (str[*i] && is_flag(str[*i]) && !is_format(str[*i]))
	{
		if (str[*i] == '#')
			flags.hash = 1;
		if (str[*i] == ' ')
			flags.space = 1;
		if (str[*i] == '+')
			flags.plus = 1;
		(*i)++;
	}
	return (ft_flag_check(flags, args, str[*i]));
}

int	ft_flag_check(t_flag flags, va_list *args, char c)
{
	if (flags.hash)
		return (ft_printf_hash(args, c));
	if (flags.space && !flags.plus)
		return (ft_printf_sign(args, 0, 1, c));
	if (flags.plus)
		return (ft_printf_sign(args, 1, 0, c));
	return (0);
}
