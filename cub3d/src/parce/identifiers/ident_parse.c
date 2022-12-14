/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ident_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:27:58 by ameteori          #+#    #+#             */
/*   Updated: 2022/11/06 23:38:54 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	skip_space(t_list **lst, t_cub *cub)
{
	int		i;
	char	*file;

	while (*lst)
	{
		i = -1;
		file = ft_strdup((*lst)->content);
		if (!file)
			err_exit(2);
		while (file[++i] == ' ' || file[++i] == '\n')
			i++;
		if (file[i] == '\0')
		{
			save_free(&file);
			ft_lstdelone_char(*lst, save_free);
			*lst = (*lst)->next;
			continue ;
		}
		else
		{
			save_free(&file);
			break ;
		}
	}
}

static void	set_ident(char *ident_str, t_cub *cub)
{
	while (*ident_str == ' ')
		ident_str++;
	if (*ident_str == 'R')
	{
		ft_putstr_fd("\t\t\t\tResolution:", 1);
		resolution(++ident_str, cub);
	}
	else
		texture(ident_str, cub);
}

static int	ident_check(char *ident_str, t_cub *cub)
{
	int	i;

	i = 0;
	while (ident_str[i] == ' ')
		i++;
	if (ident_str[i] == '\n' || ident_str[i] == '\0')
		return (NEXT);
	else if (ft_strchr("RSFCD", ident_str[i]) && ident_str[i + 1] == ' ')
		return (SUCCESS);
	else if (ft_strchr("SN", ident_str[i]) && ident_str[i + 1] == 'O')
		return (SUCCESS);
	else if (ident_str[i] == 'W' && ident_str[i + 1] == 'E')
		return (SUCCESS);
	else if (ident_str[i] == 'E' && ident_str[i + 1] == 'A')
		return (SUCCESS);
	else
		err_exit(4);
	return (ERR);
}

void	parce_ident(t_list **file_lst, t_cub *cub)
{
	int		ident;
	char	*file;

	ident = 0;
	while (ident != 9 && *file_lst)
	{
		file = ft_strdup((*file_lst)->content);
		if (!file)
			err_exit(2);
		if (ident_check(file, cub) == 1)
		{
			set_ident(file, cub);
			ident++;
		}
		save_free(&file);
		ft_lstdelone_char(*file_lst, save_free);
		*file_lst = (*file_lst)->next;
	}
	ft_putstr_fd("\n\t", 1);
	if (ident != 9)
		err_exit(3);
	skip_space(file_lst, cub);
	if (!(*file_lst) && ident == 8)
		err_exit(4);
}
