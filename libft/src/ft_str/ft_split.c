/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:45:19 by abiddane          #+#    #+#             */
/*   Updated: 2022/12/16 12:40:51 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbstr(char const *str, char c)
{
	int	i;
	int	comp;

	i = 0;
	comp = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			comp++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (comp);
}

static char	*ft_dup(char const *str, char c)
{
	char	*dest;
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		size++;
	}
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		dest[i] = str[i];
		i++;
	}	
	dest[i] = 0;
	return (dest);
}

static char	**free_all(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*word;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	ret = (char **)malloc(sizeof(char *) * (ft_nbstr(s, c) + 1));
	if (!ret)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{	
			word = ft_dup(s, c);
			ret[i] = word;
			if (!ret[i++])
				return (free_all(ret));
			s = s + ft_strlen(word);
		}
	}
	ret[i] = NULL;
	return (ret);
}
