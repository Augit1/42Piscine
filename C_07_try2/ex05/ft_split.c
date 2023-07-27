/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:42:41 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/25 12:49:04 by aude-la-         ###   ########.fr       */
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

int	find_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!find_charset(str[i], charset))
		{
			count++;
			while (str[i] && !find_charset(str[i], charset))
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	*copy_word(char *str, char *charset, int *index)
{
	int		i;
	int		word_len;
	char	*word;

	word_len = 0;
	while (str[*index + word_len]
		&& !find_charset(str[*index + word_len], charset))
		word_len++;
	word = (char *)malloc((word_len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[*index] && !find_charset(str[*index], charset))
	{
		word[i] = str[*index];
		(*index)++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		index;
	int		j;
	char	**result;

	index = 0;
	j = 0;
	result = (char **)malloc((count_word(str, charset) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (str[index])
	{
		if (!find_charset(str[index], charset))
		{
			result[j] = copy_word(str, charset, &index);
			if (result[j] == NULL)
				return (NULL);
			j++;
		}
		else
			index++;
	}
	result[j] = 0;
	return (result);
}
