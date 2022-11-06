/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:02:47 by ejafer            #+#    #+#             */
/*   Updated: 2022/11/06 16:36:20 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

void	fill_executor_struct(t_executer_utils *utils, t_plit *mini)
{
	utils->pin = -1;
	utils->pout = -1;
	utils->current_fast = *mini->tokens;
	utils->current_slow = *mini->tokens;
}

void	close_pipe(int pin, int pout)
{
	if (pin != -1)
		close(pin);
	if (pout != -1)
		close(pout);
}
