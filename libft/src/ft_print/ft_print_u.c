/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:21:33 by abiddane          #+#    #+#             */
/*   Updated: 2022/11/28 15:03:48 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbcount(unsigned int n)
{
	unsigned long int	nbr;
	int					nb;

	nbr = n;
	nb = 1;
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		nb++;
	}
	return (nb);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned long int	nbr;
	char				*str;
	int					i;

	str = malloc(sizeof(char) * (nbcount(n) + 1));
	if (!str)
		return (NULL);
	str[nbcount(n)] = '\0';
	i = nbcount(n) - 1;
	nbr = n;
	while (nbr >= 10)
	{
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	str[i] = nbr + '0';
	return (str);
}

int	ft_print_uint(unsigned int n)
{
	char	*str;
	int		i;

	str = ft_uitoa(n);
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	free(str);
	return (i);
}
