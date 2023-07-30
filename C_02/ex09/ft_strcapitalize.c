/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:14:57 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/12 18:23:00 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	uppercase(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}

char	lowercase(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (new_word)
			{
				str[i] = uppercase(str[i]);
				new_word = 0;
			}
			else
				str[i] = lowercase(str[i]);
		}
		else
			new_word = 1;
		i++;
	}
	return (str);
}
