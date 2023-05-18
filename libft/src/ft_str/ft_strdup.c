/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:34:17 by abiddane          #+#    #+#             */
/*   Updated: 2023/01/02 16:54:24 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_tabdup(char **tab)
{
	char	**dest;
	size_t	y;

	y = 0;
	dest = malloc(sizeof(char *) * (ft_tablen(tab) + 1));
	while (y < ft_tablen(tab))
	{
		dest[y] = ft_strdup(tab[y]);
		y++;
	}
	dest[y] = NULL;
	return (dest);
}
