/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:39:06 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/16 17:49:19 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_is_valide(char *str)
{
	int		i;
	int		j;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-' || str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *strl)
{
	int	l;

	if (strl == NULL)
		return (0);
	l = 0;
	while (strl[l] != '\0')
		l++;
	return (l);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	unsigned_nbr;
	int				length;

	if (base == NULL || !base_is_valide(base))
		return ;
	length = ft_strlen(base);
	if (length < 2)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		unsigned_nbr = (unsigned int)(-nbr);
	}
	else
		unsigned_nbr = (unsigned int)nbr;
	if (unsigned_nbr >= (unsigned int)length)
	{
		ft_putnbr_base(unsigned_nbr / (unsigned int)length, base);
	}
	ft_putchar(base[unsigned_nbr % (unsigned int)length]);
}
