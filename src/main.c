/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:56:31 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/14 15:56:31 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_cmd(char *s, char **env)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = -1;
	while (env[++i])
	{
		tmp = ft_strjoin(ft_strdup(env[i]), "/");
		tmp2 = ft_strjoin(tmp, s);
		if (access(tmp2, F_OK | R_OK) == 0)
			return (tmp2);
		free(tmp2);
	}
	return (NULL);
}

void	free_cmd(t_cmd *cmd)
{
	free(cmd->cmd);
	ft_free_tab(cmd->args);
}

void	start(char **av, char **path)
{
	t_cmd	cmd1;
	t_cmd	cmd2;
	int		in;
	int		out;

	in = access_file(av[1], 1);
	out = access_file(av[4], 2);
	if (!in || !out)
		return ;
	dup2(in, 0);
	dup2(out, 1);
	cmd1.args = ft_split(av[2], " ");
	cmd1.cmd = find_cmd(cmd1.args[0], path);
	cmd2.args = ft_split(av[3], " ");
	cmd2.cmd = find_cmd(cmd2.args[0], path);
	if (!cmd1.cmd || !cmd2.cmd)
	{
		ft_putstr_fd("pipex: command not found\n", 2);
		free_cmd(&cmd1);
		free_cmd(&cmd2);
		return ;
	}
	exec_pipe(&cmd1, &cmd2);
	free_cmd(&cmd1);
	free_cmd(&cmd2);
}

int	main(int ac, char **av, char **env)
{
	char	*path;
	char	**path2;

	if (ac != 5)
	{
		ft_putstr_fd("usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (0);
	}
	path = get_path("PATH=", env);
	if (!path)
	{
		ft_putstr_fd("usage: can't get environment PATH variable !\n", 2);
		return (0);
	}
	path2 = ft_split(path, ":");
	start(av, path2);
	ft_free_tab(path2);
}
