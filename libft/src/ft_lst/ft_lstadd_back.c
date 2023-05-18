/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:26:12 by abiddane          #+#    #+#             */
/*   Updated: 2022/11/17 11:59:45 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*stock;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			stock = ft_lstlast(*lst);
			stock -> next = new;
		}
	}	
}
