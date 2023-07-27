/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:23:19 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/18 16:40:50 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	test;
	int	result;

	result = 0;
	while (!result)
	{
		if (nb < 2)
			result = 0;
		test = 2;
		while (test < nb)
		{
			if ((nb % test) == 0)
				break ;
			test++;
		}
		if (test == nb)
			result = 1;
		else
			nb++;
	}
	return (nb);
}
