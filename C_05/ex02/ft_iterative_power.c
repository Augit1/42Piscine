/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:30:54 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/18 13:21:42 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	nbconst;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	nbconst = nb;
	while (power > 1)
	{
		nb *= nbconst;
		power--;
	}
	return (nb);
}
