/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:42:41 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/24 21:53:13 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	find_charset(char *str, char *charset, int index)
{
	int	i;
	int	j;

	i = index;
	j = 0;
	while (str[i] == charset[j])
	{
		i++;
		j++;
	}
	if (j == ft_strlen(charset))
		return (1);
	return (0);
}

void	alloc_strs(char **result, char *str, char *charset)
{
	int	j;
	int	index;
	int	size;
	int	len;

	len = ft_strlen(charset);
	index = 0;
	j = 0;
	size = 0;
	while (str[index])
	{
		if (find_charset(str, charset, index))
			index += len;
		size = 0;
		while (str[index] && !find_charset(str, charset, index))
		{
			size++;
			index++;
		}
		result[j] = (char *)malloc((((size + 1) + (2 * len))) * sizeof(char));
		if (result[j] == NULL)
			return ;
		index++;
		j++;
	}
}

void	ft_strcpy_in_array(char **result, char *str, char *charset, int index)
{
	int	j;
	int	k;

	index = 0;
	j = 0;
	while (result[j] && str[index])
	{
		k = 0;
		if (find_charset(str, charset, index))
			index += ft_strlen(charset);
		while (charset[k] && !find_charset(str, charset, index))
		{
			result[j][k] = charset[k];
			k++;
		}
		while (str[index] && !find_charset(str, charset, index))
			result[j][k++] = str[index++];
		while (charset[k] && !find_charset(str, charset, index))
		{
			result[j][k] = charset[k];
			k++;
		}
		result[j][k] = '\0';
		j++;
		index++;
	}
	result[j] = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		nb_charset;
	int		index;
	char	**result;

	nb_charset = 1;
	index = 0;
	while (str[index])
	{
		if (find_charset(str, charset, index))
			nb_charset++;
		index++;
	}
	result = (char **)malloc((nb_charset + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	alloc_strs(result, str, charset);
	ft_strcpy_in_array(result, str, charset, index);
	return (result);
}
