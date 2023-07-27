/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:32:13 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/22 17:52:35 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		base_is_valide(char *str);
int		read_string(char *str, char *base, int nbr, int length);

int	get_length(int nbr, int length)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr /= length;
	}
	return (i);
}

void	fill_result(int nbr, char *result, char *base, int negative)
{
	int	i;
	int	length;

	length = ft_strlen(base);
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

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	if (!str)
		return (NULL);
	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
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
		return (NULL);
	negative = 0;
	if (nbr == 0)
		return (ft_strdup(base));
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
		return (NULL);
	fill_result(temp_nbr, result, base, negative);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		nbr_dec;

	if (nbr == NULL || *nbr == '\0'
		|| !base_is_valide(base_from) || !base_is_valide(base_to))
	{
		result = (char *)malloc(1);
		if (!result)
			return (NULL);
		*result = '\0';
		return (result);
	}
	nbr_dec = read_string(nbr, base_from, 0, ft_strlen(base_from));
	result = ft_itoa_base(nbr_dec, base_to);
	if (!result)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
