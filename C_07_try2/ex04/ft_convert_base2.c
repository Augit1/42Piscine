/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:20:59 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/27 12:09:50 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_recursive_power(int nb, int p)
{
	if (p < 0)
		return (0);
	else if (p == 0)
		return (1);
	return (nb * ft_recursive_power(nb, p - 1));
}

int	get_len(long int nbr, int size, int is_neg)
{
	int	i;

	i = 0;
	if (is_neg == -1)
		i++;
	while (nbr > 0)
	{
		nbr /= size;
		i++;
	}
	return (i);
}

char	*ft_print_rc(long int nbr, char *base, char *result, int is_neg)
{
	int		i;
	int		size;

	i = 0;
	size = get_len(nbr, ft_strlen(base), is_neg);
	if (is_neg == -1)
		result[0] = '-';
	if (nbr == 0)
	{
		result[0] = base[0];
		result[1] = '\0';
	}
	while (nbr > 0)
	{
		result[(size - i - 1)] = base[nbr % ft_strlen(base)];
		i++;
		nbr /= ft_strlen(base);
	}
	return (result);
}

char	*ft_putnbr_base(long int nbr, char *base, int is_neg)
{
	long int	nb;
	char		*result;
	int			size;
	int			len;

	nb = nbr;
	size = ft_strlen(base);
	len = get_len(nb, size, is_neg);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if ((is_neg == -1 && len == 1) || (len == 0 && is_neg == 0))
	{
		result[0] = base[0];
		return (result);
	}
	return (ft_print_rc(nb, base, result, is_neg));
}
