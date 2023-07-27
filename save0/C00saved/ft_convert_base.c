/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:07:40 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/26 23:59:27 by aude-la-         ###   ########.fr       */
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

int	is_valide_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) <= 1 || ft_strlen(base) > 16)
		return (0);
	i = 0;
	j = 0;
	while (base[i])
	{
		while (base[j])
		{
			if ((base[i] == base[j]) && (i != j))
				return (0);
			j++;
		}
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		if (base[i] < 32 || base[i] > 126 || base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_base(const char *str, char *base)
{
	int	n;
	int	j;
	int	result;

	if (!is_valide_base(base))
		return (0);
	n = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n *= -1;
		str++;
	}
	while (*str)
	{
		j = 0;
		while (base[j] != *str)
			j++;
		result = result * ft_strlen(base) + j;
		str++;
	}
	return (result * n);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*duplicate;

	duplicate = (char *)malloc(ft_strlen(str) + 1);
	if (duplicate == NULL)
		return NULL;

	i = 0;
	while (str[i])
	{
		duplicate[i] = str[i];
		i++;
	}
	duplicate[i] = '\0';
	return duplicate;
}

static int	get_length(int nbr, int length)
{
	int i = 0;
	while (nbr != 0)
	{
		i++;
		nbr /= length;
	}
	return i;
}

static void	fill_result(int nbr, char *result, char *base, int negative)
{
	int i;
	int length = ft_strlen(base);

	i = get_length(nbr, length);
	result[i + negative] = '\0';
	if (negative)
		result[0] = '-';
	while (i > 0)
	{
		i--;
		result[i + negative] = base[nbr % length];
		nbr /= length;
	}
}

char	*ft_itoa_base(int nbr, char *base)
{
	int		length;
	char	*result;
	int		result_length;
	int		temp_nbr;
	int		negative;

	length = ft_strlen(base);
	if (length < 2)
		return NULL;
	negative = 0;
	if (nbr == 0)
		return ft_strdup(base);
	if (nbr < 0)
	{
		negative = 1;
		temp_nbr = -nbr;
	}
	else
		temp_nbr = nbr;
	result_length = get_length(temp_nbr, length);
	result = (char *)malloc(result_length + negative + 1);
	if (!result)
		return NULL;
	fill_result(temp_nbr, result, base, negative);
	return result;
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		value;

	result = NULL;
	if (!is_valide_base(base_from) || !is_valide_base(base_to))
		return (NULL);
	value = ft_atoi_base(nbr, base_from);
	if (value == 0)
	{
		result = (char *)malloc(2);
		result[0] = base_to[0];
		result[1] = '\0';
		return (result);
	}
	return (ft_itoa_base(value, base_to));
}
