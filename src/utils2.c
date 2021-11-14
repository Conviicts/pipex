/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:56:16 by jode-vri          #+#    #+#             */
/*   Updated: 2021/11/14 15:56:17 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *s1)
{
	char	*result;
	int		len;
	int		i;

	len = ft_strlen(s1);
	i = -1;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (s1[++i])
		result[i] = s1[i];
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	res = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return (res);
}

int	ft_strs_tab_size(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (i);
	while (tab[i])
		i++;
	return (i);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (++i <= ft_strs_tab_size(tab))
		free(tab[i]);
	free(tab);
}

int	write_error(char *s, char *error)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(error, 2);
	return (0);
}
