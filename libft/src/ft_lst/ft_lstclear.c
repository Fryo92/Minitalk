/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:07:39 by abiddane          #+#    #+#             */
/*   Updated: 2022/11/18 12:55:49 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*stock;
	t_list	*temp;

	if (!lst || !del)
		return ;
	stock = *lst;
	while (stock != NULL)
	{
		temp = stock -> next;
		ft_lstdelone(stock, del);
		stock = temp;
	}
	*lst = NULL;
}
