/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-alice.chaix-de-lavarene
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "generator.h"

int	main(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        return (-1);
    srand(getpid() * time(NULL));
    int x = my_getnbr(av[1]);
    int y = my_getnbr(av[2]);
    if (ac == 3) {
        if (good_dimensions(av[1], av[2]) == -1)
            return (-1);
        gen_imparfait(x, y);
    }
    else if (ac == 4) {
        if (good_dimensions(av[1], av[2]) == -1
        || my_strcmp("perfect", av[3]) == 1)
            return (-1);
        gen_parfait(x, y);
    }
    return (0);
}