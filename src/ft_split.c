/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 02:30:32 by vserra            #+#    #+#             */
/*   Updated: 2021/09/17 21:38:46 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

static int	ft_len_word(char *str, char *charset)
{
	int		len;

	len = 0;
	while (str[len])
	{
		if ((ft_strchr(charset, str[len]) == NULL))
			len++;
		else
			break ;
	}
	return (len);
}

static char	*ft_dup(char *src, char *charset)
{
	int		i;
	char	*dest;
	int		len;

	i = 0;
	len = ft_len_word(src, charset);
	dest = malloc(sizeof(*src) * (len + 1));
	if (dest == NULL)
		return (0);
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_count_word(char *str, char *charset)
{
	int		i;
	int		nbr_word;

	i = 0;
	nbr_word = 0;
	while (str[i])
	{
		if ((ft_strchr(charset, str[i]) == NULL) && (i == 0))
		{
			nbr_word++;
			i++;
		}
		if ((ft_strchr(charset, str[i]) == NULL)
			&& (ft_strchr(charset, str[i - 1]) != NULL))
			nbr_word++;
		i++;
	}
	return (nbr_word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		nbr_word;

	nbr_word = ft_count_word(str, charset);
	tab = malloc(sizeof(char *) * (nbr_word + 1));
	if (tab == NULL)
		return (NULL);
	tab[nbr_word] = NULL;
	i = 0;
	while (*str)
	{
		if (ft_strchr(charset, *str) == NULL)
		{
			tab[i] = ft_dup(str, charset);
			i++;
			str += ft_len_word(str, charset);
		}
		else
			str++;
	}
	return (tab);
}
