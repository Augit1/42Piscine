/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:26:38 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/20 20:52:40 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, const char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}

char	*copy_strings(char **strs, int size, size_t total_length, char *sep)
{
	int		i;
	char	*result;	
	char	*current_result;

	i = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		i++;
	}
	total_length += (size - 1) * ft_strlen(sep) + 1;
	result = (char *)malloc(total_length);
	if (!result)
		return (NULL);
	current_result = result;
	i = 0;
	while (i < size)
	{
		current_result = ft_strcpy(current_result, strs[i]);
		if (i < size - 1)
			current_result = ft_strcat(current_result, sep);
		i++;
	}
	*current_result = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*empty_str;	
	size_t	total_length;

	total_length = 0;
	if (size == 0)
	{
		empty_str = (char *)malloc(1);
		if (empty_str)
			*empty_str = '\0';
		return (empty_str);
	}
	return (copy_strings(strs, size, total_length, sep));
}
