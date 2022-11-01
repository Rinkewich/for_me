/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:30:07 by fardath           #+#    #+#             */
/*   Updated: 2022/11/01 16:04:40 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *new_token(char *name, t_type type)
{
	t_token *token;

	token = malloc(sizeof(t_token) * 1);
	token->val = name;
	token->type = type;
	token->argv = ft_arrnew(1);
	token->argv[0] = name;
	token->next = NULL;
	return (token);
}

void	token_push_back(t_token **head, t_token *to_push)
{
	t_token	*current;

	if (*head == NULL)
	{
		*head = to_push;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = to_push;
}
