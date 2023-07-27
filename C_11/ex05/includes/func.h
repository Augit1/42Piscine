/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:25:05 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/26 14:49:15 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

# include <unistd.h>
# include "operatorfunc.h"

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
void	create_functab(void (*calc_array[5])(int, int));
void	do_op(int nb_argc, char **tab);

#endif
