/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:02:49 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/13 20:41:53 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main(void)
{
	char tabtest[] = "Bonjour 3 je m'appelle00 pie77e ¿";
	char tabdest[] = "Bonjour 2 je m'appelle10pie77e ¿";

	int result = ft_strncmp(tabdest, tabtest, 15);
	printf("Le résultat est : %d\n", result);
	return (0);
}

