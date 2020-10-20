/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:28:25 by mbrunel           #+#    #+#             */
/*   Updated: 2020/03/08 14:55:06 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define NONE "\033[0m"

# define SHELL "42A2sh"
# define C_SHELL CYAN
# define C_ERROR RED
# define BUFFER_SIZE 6

pid_t				g_pid;

enum				e_sep {AND_AND, OR_OR, SEMI_COLON, PIPE,
	MORE, MORE_MORE, LESS, LESS_LESS};

enum				e_builtin {ZERO, ECHO, CD, PWD, EXPORT, UNSET, ENV, EXIT};

typedef struct		s_lst
{
	char			*text;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_magic
{
	char			*stop;
	char			*proc;
	pid_t			id;
}					t_magic;

typedef struct		s_venv
{
	int				i;
	int				len_token;
	int				todel;
	int				boo;
	char			token[256];
	char			**new_env;
}					t_venv;

typedef struct		s_args
{
	int				pre_stop;
	int				next_stop;
	int				in;
	int				out;
	struct s_magic	m;
	struct s_lst	*lst;
	struct s_args	*next;
}					t_args;

typedef struct		s_quote
{
	int				b;
	int				s;
	int				d;
	int				i;
	int				exit_status;
}					t_quote;

void				launch(int *exit_status, char **av, char **env);
int					cd(t_lst *path, char **env[]);
char				*pwd(void);
int					aff_pwd(void);
void				bye(int rt);
char				**update_env(char *env[],
						char *str, char mode);
void				launch_stuff(t_args *cmd, char *path[],
						char **env[], int *exit_status);
int					launch_one(t_args *arg, char *av[],
						char *env[], int *exit_st);
void				recup_signal(int sig);
char				*cut(char *str);
char				**export(char *env[], t_lst *lst, int mode);
int					echo(t_lst *lst);
int					aff_env(char *env[]);
t_lst				*lstnew(void);
void				lstadd(t_lst **cmd, t_lst *new);
void				lstclear(t_lst *cmd);
t_args				*argsnew(void);
void				argsadd(t_args **cmd, t_args *new);
void				argsclear(t_args *cmd);
void				gnl_call(t_args **cmd, char *env[], int *exit_status);
char				*gnl(char *tmp, char *new_line, int k);
void				quote_search(t_args **cmd, char *env[], int *exit_status);
char				*search_env(char *env_tmp, char *env[]);
void				quote_cut(t_lst **cmd, char *env[], int *exit_status);
void				quote_while(t_lst *tmp, t_quote *q,
						char **env, char *env_tmp);
void				quote_cut_second(t_lst *tmp, t_quote *q,
						char **env, char *env_tmp);
void				quote_init(t_quote *q, int exit_status);
void				rm_mult(char *text, int i, int *n);
void				put_in(char *env, t_lst *tmp, int i);
char				*cut_env(char *text, int i);
void				rm(char *text, int i);
t_args				*parse(char *line);
void				add_text(t_args *args, char *line, int *index);
int					add_text_first(char *line, int *index,
	t_lst *first, t_args *args);
void				add_text_second(char *line, int *opt,
	t_lst *first, int *index);
void				add_text_third(char *line, int *opt,
	t_lst *first, int *index);
t_lst				*add_text_fourth(char *line, int *opt,
	t_lst *first, int *index);
void				add_text_fifth(char *line, int *opt,
	t_lst *new, int *index);
int					add_text_sixth(char *line, int *index,
	t_args *args, int *opt);
void				add_text_seventh(char *line, int *opt,
	int *index, t_args *args);
t_lst				*add_text_while(char *line, int *opt,
	t_lst *first, int *index);
void				prev_stop(t_args **cmd);
int					is_normal(char c, int *opt);
void				space(char *line, int *index);
void				recup_signal(int sig);
void				reset_std(int in, int out);
void				save_std(int *in, int *out);
void				set_std(t_args *arg);
char				*prog_path(char *name, char *env[]);
int					launch_builtin(int builtin, t_args *arg, char **env[]);

#endif
