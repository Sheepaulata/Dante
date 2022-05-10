/*
** EPITECH PROJECT, 2020
** my_put.c
** File description:
** for all puts
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1 , &c , 1);
}

int my_putstr(char const *str)
{
    int i;
    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_put_nbr(-214748364);
        my_putchar('8');
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
        return (0);
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
    return 0;
}
