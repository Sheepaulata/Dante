/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-alice.chaix-de-lavarene
** File description:
** len
*/

#include "solver.h"

int my_strlen(const char *str)
{
    int len = 0;
    for (; str[len]; len++);
    return (len);
}

int string_len(char *str, char c)
{
    int len = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            len++;
    return (len);
}