/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:45:57 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/19 15:21:15 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*---------------BONUS------------------*/
typedef struct s_flag
{
	int	plus;
	int	space;
	int	hash;
}				t_flag;

int		ft_printf_hash(va_list *args, char c);
int		ft_printf_sign(va_list *args, int is_plus, int is_space, char c);
int		is_flag(char c);
int		ft_flag_parsing(va_list *args, const char *str, int *i);
int		ft_flag_check(t_flag flags, va_list *args, char c);

void	init_struct(t_flag *flags);

/*---------------utils------------------*/
size_t	ft_strlen(const char *s);

char	*ft_strdup_itoa(char *s1, int size, int is_negative);
char	*ft_strdup_itoa_unsigned(char *s1, int size);
char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);

/*---------------ft_printf------------------*/
int		is_format(char c);
int		ft_format_printf(va_list *args, char c);
int		ft_printf(const char *str, ...);
int		ft_printf_char(int c);
int		ft_printf_str(const char *str);
int		ft_printf_nbr(int nb);
int		ft_printf_unsigned(unsigned int nb);
int		ft_printf_hexa(unsigned int nb, int uppercase);
int		ft_printf_ptr(void *address);

void	ft_hexa_ptr(unsigned long long nb);

#endif
