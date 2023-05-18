/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:50:32 by abiddane          #+#    #+#             */
/*   Updated: 2022/11/17 17:00:19 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = 0;
	k = ft_strlen(s1) - 1;
	while (s1[j] && isset(s1[j], set))
		j++;
	while (k > j && isset(s1[k], set))
		k--;
	str = malloc(sizeof(char) * (k - j + 2));
	if (!str)
		return (NULL);
	while (j <= k)
	{
		str[i] = s1[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
