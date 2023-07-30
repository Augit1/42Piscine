/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:40:39 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/10 16:51:25 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_putchar((i / 10) + '0');
			ft_putchar((i % 10) + '0');
			ft_putchar(' ');
			ft_putchar((j / 10) + '0');
			ft_putchar((j % 10) + '0');
			if (i != 98 || j != 99)
			{
				write(1, ", ", 2);
			}
			j++;
		}
		i++;
	}
	ft_putchar('\n');
}
