/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:22:22 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/22 14:34:38 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int main()
{
    char *result;

    // Test 1: Conversion binaire vers décimale
    char binary_num[] = "1101";
    char base_from_binary[] = "01";
    char base_to_decimal[] = "0123456789";
    result = ft_convert_base(binary_num, base_from_binary, base_to_decimal);
    printf("Conversion binaire vers décimale: %s\n", result);
    free(result);

    // Test 2: Conversion décimale vers hexadécimale
    char decimal_num[] = "255";
    char base_from_decimal[] = "0123456789";
    char base_to_hex[] = "0123456789ABCDEF";
    result = ft_convert_base(decimal_num, base_from_decimal, base_to_hex);
    printf("Conversion décimale vers hexadécimale: %s\n", result);
    free(result);

    // Test 3: Conversion hexadécimale vers binaire
    char hex_num[] = "1F";
    char base_from_hex[] = "0123456789ABCDEF";
    char base_to_binary[] = "01";
    result = ft_convert_base(hex_num, base_from_hex, base_to_binary);
    printf("Conversion hexadécimale vers binaire: %s\n", result);
    free(result);

    // Test 4: Conversion binaire vers hexadécimale (avec base incorrecte)
    char binary_num2[] = "110101";
    char base_from_binary2[] = "01";
    char base_to_hex2[] = "0123456789ABCDEF";
    result = ft_convert_base(binary_num2, base_from_binary2, base_to_hex2);
    if (result == NULL)
        printf("Erreur de conversion (base incorrecte)\n");
    free(result);

    return 0;
}
