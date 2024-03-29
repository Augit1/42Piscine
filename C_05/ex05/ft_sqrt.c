/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:35:19 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/18 18:44:11 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	x;
	int	y;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (0);
	x = nb;
	y = (x + nb / x) / 2;
	while (y < x)
	{
		x = y;
		y = (x + nb / x) / 2;
	}
	if (x * x == nb)
		return (x);
	else
		return (0);
}
