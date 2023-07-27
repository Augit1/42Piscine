/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:23:01 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/26 14:46:56 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	nbr;

	i = 0;
	n = 0;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 12))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (n % 2 == 1)
		return (-nbr);
	else
		return (nbr);
}

void	create_functab(void (*calc_array[5])(int, int))
{
	calc_array[0] = add;
	calc_array[1] = sub;
	calc_array[2] = div;
	calc_array[3] = mod;
	calc_array[4] = mult;
}

void	do_op(int nb_argc, char **tab)
{
	int		v1;
	int		v2;
	int		op;
	void	(*calc_array[5])(int, int);

	if (nb_argc != 4)
		return ;
	v1 = ft_atoi(tab[1]);
	v2 = ft_atoi(tab[3]);
	op = tab[2][0];
	create_functab(calc_array);
	if (op == '+')
		calc_array[0](v1, v2);
	else if (op == '-')
		calc_array[1](v1, v2);
	else if (op == '/')
		calc_array[2](v1, v2);
	else if (op == '%')
		calc_array[3](v1, v2);
	else if (op == '*')
		calc_array[4](v1, v2);
	else
		write(1, "0", 1);
	ft_putchar('\n');
}
