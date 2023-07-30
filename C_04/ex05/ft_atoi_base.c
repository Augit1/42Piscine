/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:13:36 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/17 15:42:54 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_is_valide(char *str)
{
	int		i;
	int		j;

	if (str == (void *)0)
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

int	ft_strlen(char *strl)
{
	int	l;

	if (strl == (void *)0)
		return (0);
	l = 0;
	while (strl[l] != '\0')
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
	while (str[i] == ' ')
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

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;
	int	length;

	length = ft_strlen(base);
	if (length < 2 || !base_is_valide(base))
		return (0);
	nbr = 0;
	nbr = read_string(str, base, nbr, length);
	return (nbr);
}
