/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatorfunc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:16:52 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/25 22:18:51 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operatorfunc.h"

void	add(int v1, int v2)
{
	ft_putnbr(v1 + v2);
}

void	sub(int v1, int v2)
{
	ft_putnbr(v1 - v2);
}

void	div(int v1, int v2)
{
	if (v2 == 0)
	{
		write(1, "Stop : division by zero", 23);
		return ;
	}
	ft_putnbr(v1 / v2);
}

void	mod(int v1, int v2)
{
	if (v2 == 0)
	{
		write(1, "Stop : modulo by zero", 21);
		return ;
	}
	ft_putnbr(v1 % v2);
}

void	mult(int v1, int v2)
{
	ft_putnbr(v1 * v2);
}
