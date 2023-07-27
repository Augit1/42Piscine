/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:26:38 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/20 19:49:48 by aude-la-         ###   ########.fr       */
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

void	copy_strings(char *result, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	k;	
	int	result_index;

	result_index = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			result[result_index] = strs[i][j];
			result_index++;
			j++;
		}
		if (i < size - 1)
		{
			k = 0;
			while (sep[k])
			{
				result[result_index] = sep[k];
				result_index++;
				k++;
			}
		}
		i++;
	}
	result[result_index] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		strs_size;
	int		sep_size;
	int		total_size;
	char	*result;

	if (size <= 0 || strs == NULL || sep == NULL)
		return (NULL);
	if (*strs == NULL)
		return (NULL);
	strs_size = 0;
	sep_size = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		if (strs[i] == NULL)
			return (NULL);
		strs_size += ft_strlen(strs[i]);
		i++;
	}
	total_size = strs_size + sep_size * (size - 1) + 1;
	result = (char *)malloc(total_size);
	if (result == NULL)
		return (NULL);
	copy_strings(result, strs, sep, size);
	return (result);
}
