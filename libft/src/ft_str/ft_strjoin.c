/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:44:28 by abiddane          #+#    #+#             */
/*   Updated: 2022/12/16 16:14:05 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str, char *buf)
{
	size_t		i;
	size_t		j;
	char		*dest;

	i = 0;
	if (!str)
	{
		str = ft_calloc(1, sizeof(char));
		str[0] = '\0';
	}
	dest = ft_calloc((ft_strlen(str) + ft_strlen(buf) + 1), sizeof(char));
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	j = 0;
	while (buf[j])
		dest[i++] = buf[j++];
	free(str);
	dest[i] = '\0';
	return (dest);
}
