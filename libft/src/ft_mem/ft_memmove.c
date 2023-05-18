/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:38:03 by abiddane          #+#    #+#             */
/*   Updated: 2022/11/17 16:44:45 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest1;
	char	*src1;

	i = -1;
	dest1 = dest;
	src1 = (char *)src;
	if (!dest && !src)
	{
		n = 0;
		return (NULL);
	}
	if (dest > src)
	{
		while (n-- > 0)
			dest1[n] = src1[n];
	}
	else
	{
		while (++i < n)
			dest1[i] = src1[i];
	}
	return (dest);
}
