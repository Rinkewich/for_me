/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 23:31:17 by sherbert          #+#    #+#             */
/*   Updated: 2022/11/06 23:25:43 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone_char(t_list *lst, void (*del)(char**))
{
	if (lst)
	{
		if (del && lst->content)
			del((void *)&(lst->content));
		free(lst);
	}
}
