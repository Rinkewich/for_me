/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:24:01 by fardath           #+#    #+#             */
/*   Updated: 2022/10/31 20:02:53 by fardath          ###   ########.fr       */
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

void		parser(t_plit *split);
t_parser	*init_parser(char **split);
char		*check_word(t_parser *data);
int			find_redirect(t_parser *data);
int			find_heredoc(char *word);
int	find_redirout(char *word);
int	find_redirin(char *word);
int	find_redirout_a(char *word);
void put_redirect(t_plit *split, t_parser *data);
#endif