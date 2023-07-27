/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:32:13 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/22 15:50:25 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		base_is_valide(char *str);
int		get_value(char c, char *base);
int		ft_strlen(char *str);
int		read_string(char *str, char *base, int nbr, int length);
char	*ft_strrev(char *str);
char	*ft_itoa_base(int nbr, char *base);
char	*ft_strdup(char *str);

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

int	get_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	l;

	if (str == NULL)
		return (0);
	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
}

int	read_string(char *str, char *base, int nbr, int length)
{
	int	i;
	int	n;
	int	value;

	i = 0;
	n = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 12))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n++;
		i++;
	}
	while (str[i])
	{
		value = get_value(str[i], base);
		if (value == -1 || value >= length)
			break ;
		nbr = nbr * length + value;
		i++;
	}
	if (n % 2 != 0)
		return (-nbr);
	return (nbr);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*duplicate;

	duplicate = (char *)malloc(ft_strlen(str) + 1);
	if (duplicate == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		duplicate[i] = str[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
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
	int		i;
	int		temp_nbr;
	int		negative;

	length = ft_strlen(base);
	if (length < 2)
		return (NULL);
	negative = 0;
	i = 0;
	if (nbr == 0)
		return (ft_strdup(base));
	if (nbr < 0)
	{
		negative = 1;
		temp_nbr = -nbr;
	}
	else
		temp_nbr = nbr;
	while (temp_nbr != 0)
	{
		i++;
		temp_nbr /= length;
	}
	result = (char *)malloc(i + negative + 1);
	if (!result)
		return (NULL);
	result[i + negative] = '\0';
	if (negative)
		result[0] = '-';
	temp_nbr = (negative == 1) * -nbr + (negative == 0) * nbr;
	while (i > 0)
	{
		i--;
		result[i + negative] = base[temp_nbr % length];
		temp_nbr /= length;
	}
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
