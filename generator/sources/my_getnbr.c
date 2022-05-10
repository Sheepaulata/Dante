/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** getnbr
*/

int is_mynbr_positive(char *str)
{
    int i = 0;
    int nbrmoins = 0;
    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            nbrmoins++;
        }
        i++;
    }
    if (nbrmoins % 2 == 0) {
        return (1);
    }
    else
        return (0);
}

int my_getnbr(char *str)
{
    int result = 0;
    int nbr = 0;
    int i = 0;
    int is_positive = is_mynbr_positive(str);
    while (str[i] == '+' || str[i] == '-') {
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        nbr = str[i] - '0';
        result = result *10 + nbr;
        i++;
    }
    if (is_positive == 0) {
        result *= -1;
    }
    return (result);
}
