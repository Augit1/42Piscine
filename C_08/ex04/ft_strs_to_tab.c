/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:39:42 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/23 20:23:53 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*strcpy;

	strcpy = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (strcpy == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		strcpy[i] = src[i];
		i++;
	}
	strcpy[i] = '\0';
	return (strcpy);
}

t_stock_str	fill_struct(char *str)
{
	t_stock_str	stock;

	stock.size = ft_strlen(str);
	stock.str = str;
	stock.copy = ft_strdup(str);
	return (stock);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*struct_array;

	struct_array = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (struct_array == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		struct_array[i] = fill_struct(av[i]);
		i++;
	}
	struct_array[i].str = 0;
	struct_array[i].copy = 0;
	return (struct_array);
}
