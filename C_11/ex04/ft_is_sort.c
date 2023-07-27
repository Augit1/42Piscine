/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:26:34 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/26 13:54:36 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	cmp;
	int	sorted_up;
	int	sorted_down;

	sorted_up = 1;
	sorted_down = 1;
	i = 0;
	while (i < (length - 1))
	{
		cmp = (*f)(tab[i], tab[i + 1]);
		if (cmp > 0)
			sorted_up = 0;
		else if (cmp < 0)
			sorted_down = 0;
		i++;
	}
	if (sorted_up || sorted_down)
		return (1);
	return (0);
}
