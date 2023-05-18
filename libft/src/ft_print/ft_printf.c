/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:21:38 by abiddane          #+#    #+#             */
/*   Updated: 2022/11/28 15:03:04 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_flags(va_list args, char f)
{
	int	len;

	len = 0;
	if (f == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (f == '%')
		len += ft_print_percent();
	else if (f == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (f == 'd' || f == 'i')
		len += ft_print_int(va_arg(args, int));
	else if (f == 'u')
		len += ft_print_uint(va_arg(args, unsigned int));
	else if (f == 'x' || f == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), f);
	else if (f == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_get_flags(arg, s[i + 1]);
			i++;
		}
		else
			len += ft_print_char(s[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
