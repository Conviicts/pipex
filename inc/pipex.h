/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:55:50 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/14 15:55:52 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# define READ 0
# define WRITE 1

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
}	t_cmd;

int		ft_strlen(char *s);
int		ft_putstr_fd(char *s, int fd);
char	**ft_split(char *str, char *charset);
char	*get_path(char *s1, char **env);
void	print_error(char *s);
void	ft_free_tab(char **tab);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	exec_pipe(t_cmd *cmd, t_cmd *cmd2);
int		write_error(char *s, char *error);
int		access_file(char *s, int mode);

#endif