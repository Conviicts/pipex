/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:02:15 by admin             #+#    #+#             */
/*   Updated: 2021/09/19 06:03:30 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (fd && s)
	{
		write(fd, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	return (0);
}

char	*get_path(char *s1, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], s1, 5) == 0)
			return (env[i] + 5);
	}
	return (NULL);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	if (n <= 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	access_file(char *s, int mode)
{
	if (mode == 1)
	{
		if (access(s, F_OK))
			return (write_error(s, " : No such file or directory\n"));
		else if (access(s, R_OK))
			return (write_error(s, " : Permission denied\n"));
		return (open(s, O_RDONLY));
	}
	else
		return (open(s, O_CREAT | O_WRONLY | O_TRUNC));
}
