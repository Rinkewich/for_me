/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 02:53:47 by ejafer            #+#    #+#             */
/*   Updated: 2022/11/06 16:36:20 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	post_execution(t_plit *mini)
{
	clear_tokens(*mini->tokens);
	free(mini->tokens);
	mini->tokens = NULL;
}
