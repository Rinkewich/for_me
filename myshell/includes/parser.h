/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:24:01 by fardath           #+#    #+#             */
/*   Updated: 2022/10/30 17:44:51 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "minishell.h"

typedef struct s_parser
{
	char			**words;
	int				command_is_set;
	int				index;
	t_token			*current_command;
	t_token			**head;
}	t_parser;
#endif