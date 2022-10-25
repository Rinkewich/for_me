/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hed.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:36:26 by fardath           #+#    #+#             */
/*   Updated: 2022/10/25 20:20:59 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HED_H
# define HED_H
//change struct
typedef struct s_token
{
	char			*val;
	int				type;
  char            **argv;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;
//new struct
typedef struct s_plit
{
  int argc;
  int   temporary;
  char  **argv;
  char  **env;
  char  *line;
  char  **split_line;
  int  pid;
  t_token  **tokens;
}   t_plit;

t_plit	*init_plit(int argc, char **argv, char **env);
char	**init_env_lvl(char **env);
int env_place(char *val, char **envc);
char *env_find_val(char *val, char **envc);
char	**export_var(char *arg, char **env);
char	*ft_strcpy_len(char *src, int len);
char	**add_var(char **env, char *arg);
char	**unset_var(char *var, char **env);
void	free_env(char **env);
char	**delete_var(char **env, int pos);
#endif