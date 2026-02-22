/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:44:02 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/19 15:34:14 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_printf(va_list *args, char c)
{
	int	count;

	count = 0;
	if (c == '%')
		count += write(1, "%", 1);
	else if (c == 'c')
		count += ft_printf_char(va_arg(*args, int));
	else if (c == 's')
		count += ft_printf_str(va_arg(*args, const char *));
	else if (c == 'd' || c == 'i')
		count += ft_printf_nbr(va_arg(*args, int));
	else if (c == 'u')
		count += ft_printf_unsigned(va_arg(*args, unsigned int));
	else if (c == 'x')
		count += ft_printf_hexa(va_arg(*args, unsigned int), 0);
	else if (c == 'X')
		count += ft_printf_hexa(va_arg(*args, unsigned int), 1);
	else if (c == 'p')
		count += ft_printf_ptr(va_arg(*args, void *));
	return (count);
}

int	is_format(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}

int	is_flag(char c)
{
	if (c == '#' || c == ' ' || c == '-' || c == '+' || c == '.'
		|| c == '0' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] && is_format(str[i]) && !is_flag(str[i]))
				count += ft_format_printf(&args, str[i]);
			if (str[i] && !is_format(str[i]) && is_flag(str[i]))
				count += ft_flag_parsing(&args, str, &i);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
/*
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("-------------TEST 1---------------\n");
	printf("printf -> %d test %s oui ; %%c = %c %i, %%\n", 1, "oui",
	 'a', 2);
	ft_printf("ft_printf -> %d test %s oui ; %%c = %c %i, %%\n\n",
	 1, "oui", 'a', 2);

	int	test = 42;
	printf("-------------TEST 2---------------\n");
	printf("printf -> adresse = %p, %%u = %u, %%x = %x,
	 %%X = %X\n", &test, test, test, test);
	ft_printf("ft_printf -> adresse = %p, %%u = %u,
	 %%x = %x, %%X = %X\n\n", &test, test, test, test);
	
	int	test2 = -42;
	printf("-------------TEST 3---------------\n");
	printf("printf -> adresse = %p, %%u = %u, %%x = %x,
	 %%X = %X\n", &test2, test2, test2, test2);
	ft_printf("ft_printf -> adresse = %p, %%u = %u,
	 %%x = %x, %%X = %X\n\n", &test2, test2, test2, test2);

	printf("-------------TEST 4---------------\n");
	printf("printf -> %%p = %p et NULL = %p\n", &test, NULL);
	ft_printf("ft_printf -> %%p = %p et NULL = %p\n\n", &test, NULL);
	
	printf("-------------TEST 5---------------\n");
	printf("printf -> int_max = %d ; int_min = %i\n", INT_MAX, INT_MIN);
	ft_printf("ft_printf -> int_max = %d ; int_min = %i\n\n", INT_MAX, INT_MIN);
	
	printf("-------------TEST 6---------------\n");
	printf("printf -> uint_max = %i\n", UINT_MAX);
	ft_printf("ft_printf -> uint_max = %i\n\n", UINT_MAX);
	
	printf("-------------TEST 7---------------\n");
	//printf("printf -> ptr de 0 = %p et %p\n", 0, 0);
	ft_printf("ft_printf -> ptr de 0 = %p et %p\n\n", 0, 0);

	printf("-------------TEST 8---------------\n");
	//printf("printf -> string null = %s\n", NULL);
	ft_printf("ft_printf -> string null = %s\n", NULL);

	printf("\n");
	printf("BOOOOOOOOOOOOOOOOOOONUS\n");
	printf("1) # +\n");
	printf("-------------1) TEST 1 BONUS---------------\n");
	printf("printf -> avec %%#x = %#x ; %%#X = %#X\n", test, test);
	ft_printf("ft_printf -> avec %%#x = %#x ; %%#X = %#X\n\n", test, test);
	
	printf("-------------1) TEST 2 BONUS---------------\n");
	printf("printf -> avec %%+d = %+d ; %% d = % d\n", test, test);
	ft_printf("ft_printf -> avec %%+d = %+d ; %% d = % d\n\n", test, test);

	printf("-------------1) TEST 3 BONUS---------------\n");
	//printf("printf -> string + space = % s", "salut");
	ft_printf("ft_printf -> string + space = % s", "salut");
	
	return (0);
}*/
