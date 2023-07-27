/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:26:18 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/22 17:39:30 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		i;
	int		value;
	int		size;
	int		*tabint;

	value = min;
	if (min >= max)
		return (NULL);
	size = max - min;
	tabint = (int *)malloc((size + 1) * sizeof(int));
	if (tabint == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tabint[i] = value;
		value++;
		i++;
	}
	return (tabint);
}
