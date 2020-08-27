/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 23:11:24 by marvin            #+#    #+#             */
/*   Updated: 2019/11/17 21:43:46 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static void	ft_free(char **dest, int wcount)
{
	while (wcount >= 0)
	{
		free(dest[wcount]);
		dest[wcount] = 0;
		wcount--;
	}
	free(dest);
	dest = 0;
}

static int	ft_countletter(char *s, char c, int i)
{
	int j;

	j = 0;
	while (s[i + j] != 0 && s[i + j] != c)
		j++;
	return (j);
}

static char	**ft_fillword(char *s, char c, char **dest, int *i)
{
	while (s[i[0]] && ++i[2] >= -5)
	{
		while (s[i[0]] == c && s[i[0]] != 0)
			i[0]++;
		if (s[i[0]] == 0)
			dest[i[2]] = 0;
		if (s[i[0]] == 0)
			return (dest);
		if (!(dest[i[2]] =
		malloc((ft_countletter(s, c, i[0]) + 1) * sizeof(char))))
		{
			ft_free(dest, i[2]);
			return (0);
		}
		i[1] = 0;
		while (s[i[0]] != c && s[i[0]] != 0)
		{
			dest[i[2]][i[1]] = s[i[0]];
			i[0]++;
			i[1]++;
		}
		dest[i[2]][i[1]] = 0;
	}
	dest[i[2] + 1] = 0;
	return (dest);
}

static int	ft_countword(char *s, char c)
{
	int		i;
	int		wcount;

	i = 0;
	wcount = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == 0)
			return (wcount);
		wcount++;
		while (s[i] != c && s[i] != 0)
			i++;
	}
	return (wcount);
}

char		**ft_split(char const *s, char c)
{
	char	**dest;
	int		w_count;
	int		i[3];

	i[0] = 0;
	i[1] = -1;
	if (!s)
		return (0);
	w_count = ft_countword((char *)s, c);
	i[2] = -1;
	if (!(dest = malloc((w_count + 1) * sizeof(char *))))
		return (0);
	dest = ft_fillword((char *)s, c, dest, i);
	return (dest);
}
