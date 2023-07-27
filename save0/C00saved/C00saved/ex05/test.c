/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:38:22 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/10 15:15:56 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int		i;
	char	c;

	i = 0;
	while (i <= 789)
	{
		c = i / 100 + '0';
		if (c < ((i / 10) % 10) + '0' && ((i / 10) % 10) + '0' < (i % 10) + '0')
		{
			ft_putchar(c);
			ft_putchar(((i / 10) % 10) + '0');
			ft_putchar((i % 10) + '0');
			if (i != 789)
			{
				write(1, ", ", 2);
			}
		}
		i++;
	}
	ft_putchar('\n');
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
