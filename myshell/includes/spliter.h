/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:33:09 by fardath           #+#    #+#             */
/*   Updated: 2022/10/28 19:26:28 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITER_H
# define SPLITER_H

typedef struct s_split_data
{
	char	*line;
	int		index;
	char	**words;
}	t_split_data;

# define QUOTES_D	'"'
# define QUOTES_S	'\''
# define SPACE		' '

# define HEREDOC	"<<"
# define REDIRIN	"<"
# define REDIROUT	">"
# define REDIROUT_A ">>"
# define PIPE		"|"

void spliter(t_plit *split);
char check_letter(t_split_data *data);
int check_separator(t_split_data *data);
#endif