/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:21:31 by abiddane          #+#    #+#             */
/*   Updated: 2022/11/28 15:03:34 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptr_len(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

void	ft_put_ptr(unsigned long long n)
{
	if (n >= 16)
	{
		ft_put_ptr(n / 16);
		ft_put_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			ft_putchar_fd((n - 10 + 'a'), 1);
		}	
	}	
}

int	ft_print_ptr(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	len += write(1, "0x", 2);
	len += ft_ptr_len(n);
	ft_put_ptr(n);
	return (len);
}
