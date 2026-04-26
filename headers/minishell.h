/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfeijoei <sfeijoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:43:44 by sfeijoei          #+#    #+#             */
/*   Updated: 2026/04/24 13:39:53 by sfeijoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define _POSIX_C_SOURCE 200809L

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <limits.h>
# include <sys/errno.h>
# include <termcap.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include <stdbool.h>

extern volatile sig_atomic_t	g_signal;

typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_IN,
	HEREDOC,
	AMPERSAND,
	AMPERSAND_D,
	DOUBLE_PIPE,
	BIDIREC
}	t_token_type;

typedef enum e_quote_type
{
	NONE,
	SINGLE,
	DOUBLE,
}	t_quote_type;

typedef struct s_token
{
	char			*text;
	t_token_type	type;
	t_quote_type	quote;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_redir
{
	int		type;
	char	*file;
	int		fd_heredoc;
	int		heredoc_expand;
	char	*heredoc_file;
}	t_redir;

typedef struct s_cmd
{
	char	**args;
	char	*path;
	t_redir	*redirs;
	int		redir_count;
	int		infile;
	int		outfile;
}	t_cmd;

typedef struct s_env
{
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_exec
{
	int		cmd_count;
	t_cmd	*cmds;
	pid_t	*pid;
	int		pipe_a[2];
	int		pipe_b[2];
	int		inuse;
	char	**paths;
	int		*status;
	t_env	*env;
	char	**envp;
	int		last_status;
	t_token	*tokens;
}	t_exec;

// main.c
void			free_env(t_env *env);
void			free_tokens(t_token *tokens);

// lexer.c
t_token			*tokenize(char *line);
t_quote_type	get_quote_state(char *str);

// lexer_utils.c
bool			is_separator(char c);
void			ft_lstadd_back_token(t_token **lst, t_token *new);
bool			is_quote_ok(t_token *head, char *line);
t_token_type	get_token_type(char *line, int i);

// parser.c
void			parser(t_token *head, t_exec *pipex);
bool			is_redir(t_token *token);
bool			is_syntax_valid(t_token *head);

// parser_utils.c
int				count_cmd(t_token *head);
int				count_args(t_token *head);
int				count_redirs(t_token *head);
void			init_parsing(t_token *head, t_exec *pipex);
void			fill_redir_cmd(t_token *head, t_exec *pipex, int i, int *k);
bool			first_token_error(t_token *head);

// parser_utils2.c
bool			syntax_error(char *token);
char			*get_token_str(int type);
int				has_quotes(char *str);
char			*strip_quotes(char *str);

// signals.c
void			setup_signals(void);
void			handle_sigint(int sig);
void			setup_signals_exec(void);
void			setup_signals_heredoc(void);

// environment.c
t_env			*set_env(char **env);

// expand.c
void			expand(t_exec *pipex);

// expand_utils.c
char			*expand_var(char *result, char *str, int *i, t_exec *pipex);
char			*expand_dollar_question(char *result, t_exec *pipex);
char			*handle_dollar(char *result, char *str, int *i, t_exec *pipex);
int				get_var_len(char *str);

// main_utils.c
void			init_main(t_exec *exec, int ac, char **av, char **envp);

///EXEC///

int				exec_core(t_exec *exec);
int				is_builtin(char **str);
int				handle_heredoc(t_exec *exec);
void			exec_cmd(t_exec *exec, t_cmd *cmd, int i);
int				exec_pipeline(t_exec *exec);
int				find_cmd_path(char **cmd, char **paths, char **path);
int				find_env_path(t_exec *exec);
int				update_env(t_exec *exec);
int				plug_redirs(t_cmd *cmd);
int				wait_heredoc_child(pid_t pid, int read_fd);
int				is_delimiter_line(char *line, char *delimiter);
char			*expand_heredoc_line(char *line, t_exec *exec);
int				save_heredoc(int fd, char *delimiter, int do_expand,
					t_exec *exec);

///BUILTINS///
int				exec_builtin(t_exec *exec, t_cmd *cmd);
int				exec_echo(char **cmd);
int				exec_env(t_env *envp, char **cmd);
int				exec_pwd(char **cmd);
int				exec_cd(char **cmd, t_env **env);
int				exec_unset(t_env **envp, char **cmd);
int				exec_export(t_env **envp, char **cmd);
int				export_core(t_env **envp, char *cmd);
int				exec_exit(char **cmd, t_exec *exec);
int				ft_strcmp_key(char *s1, char *s2);
void			close_pipe(t_exec *exec, int i);
int				ft_dup(t_exec *exec, t_cmd *cmd, int i);
int				*get_pipe(t_exec *exec, int i);

///UTILS///
int				ft_strcmp(char *s1, char *s2);
int				count_arg(char **cmd);
int				is_valid_identifier(char *cmd, int x);
char			*get_env_value(t_env *env, char *key);

///CLEAR///
void			free_tab(char **tab);
void			*free_partial_tab(char **tab, int size);
void			close_all_exec(t_exec *exec);
void			free_redirs(t_redir *redirs, int count);
void			free_cmd(t_cmd *cmd);
void			cleanup(t_exec *exec);
void			init_cmd(t_cmd *cmd);
void			init_struc(t_exec *exec);

#endif