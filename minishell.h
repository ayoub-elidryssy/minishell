/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:14:59 by aelidrys          #+#    #+#             */
/*   Updated: 2023/05/13 16:15:11 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define  MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <stdarg.h>
# include <termios.h>
# include <signal.h>
# include "includes/mshell.h"

t_shell	*shell;

//                    #environment#                //

// it creates a linked list of einvironment varibles //
char	**get_key_and_val(t_shell *shell, char *s, char	**d, size_t	x);
t_env	*new_env(char *s, int i);
void	add_back(t_env **env, t_env *new_env);
// it get a environment varibles //
t_env	*a_get_env(t_env *env, char *key);
// it appdate PWD and OLDPWD //
void	apdate_pwd_and_oldpwd(t_shell *shell, t_env *env, int x);
// it adde a new environment //
void	add_env(t_shell *shell, char *str);
// it convertes the environment from linked list to string //
char	**convert_env(t_env *env);
// it sorting the env linked list for export //
void	sort_env(t_env *env);
t_env	*get_min(t_env *env);

//                      #cmd#                  //

// it creates a linked list of cmd //
void	cmd_list(t_shell *shell);
void	add_cmd(t_cmd **list, t_cmd *new_cmd);
void	free_cmd(t_cmd *cmd);
// it executes one command //
void	one_cmd(t_shell *shell, t_cmd *cmd);
// it executees the first command //
void	first_cmd(t_shell *shell, t_cmd *cmd);
// it executes the cmd between the first and the last command//
void	cmd_x(t_shell *shell, t_cmd *cmd);
// it executes multible cmd //
void	multible_cmd(t_shell *shell, t_cmd *cmd, int a);
// it executees the last command //
void	last_cmd(t_shell *shell, t_cmd *cmd);

//                      #builtins#                       //

// it executes the command if cmd is a builtins command //
int		builtine(t_shell *shell, t_cmd *cmd);
// builtins cmd //
void	a_export(t_cmd *cmd, t_shell *shell);
void	a_unset(t_shell *shell, t_cmd *cmd);
void	delete_env(t_shell *shell, char *key, int s);
void	a_cd(t_shell *shell, t_cmd *cmd, char *new_dir);
void	a_env(t_env *env, char *option, int fd);
void	a_exit(t_shell *shell, t_cmd *cmd);
void	a_echo(t_cmd *cmd, char **s);
// it checkes if the command echo chould display a new line //
int		whit_newline(char **s);
// it checkes if the key is accepted //
int		check_key(t_shell *shell, char *key, char *cmmd, int a);

//  //
void	minishell(t_shell *shell);
void	a_start(t_shell *shell, char **env, int ac);
int		ft_comper(char *min_s, char *str);
char	*a_strjoin(char *s1, char *s2, int s, int x);
int		str_comp(char *s1, char *s2);
size_t	list_size(void *lst, int s);
void	a_printf(char *s1, char *s2, char *s3, int fd);
int		str_to_int(char *s);
size_t	a_strlen(char *s);
void	rl_replace_line(const char *str, int n);
// sgnals //
void	sigint_hand(int sige);
void	setup_term(void);

//             #pipe#           //

void	waiting(int x);
void	print_error1(char *s1, int x);
char	*get_pth(t_env *env, char *cmd, int n);
void	add_pid(t_pid **list, pid_t pid1);
char	**spl(char*s, char c, int n);
void	check_error(int a, int b);
void	ft_free(char **arry);
pid_t	ft_fork(t_shell *shell);

#endif