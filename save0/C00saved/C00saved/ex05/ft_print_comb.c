/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:15:38 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/10 15:28:37 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int		i;
	int		j;
	int		k;
	char	numbers[3];

	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				numbers[0] = i + '0';
				numbers[1] = j + '0';
				numbers[2] = k + '0';
				write(1, &numbers, 3);
				if (i != 7 || j != 8 || k != 9)
					write(1, ", ", 2);
				k++;
			}
			j++;
		}
	i++;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
