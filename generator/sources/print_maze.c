/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-alice.chaix-de-lavarene
** File description:
** print_maze
*/

#include <stdio.h>
#include "generator.h"

void print_maze(char **maze, int largeur, int hauteur)
{
    int i = 0;
    int d = 0;
    int	j;
    int	dont_print = 0;
    while (i < hauteur) {
        j = 0;
        while (j < largeur) {
            if (i == hauteur - 1 && j == largeur - 1 && maze[i][j] == '1') {
                my_putchar('*');
                dont_print = 1;
            } if (maze[i][j] == '0')
                my_putchar('*');
            if (maze[i][j] == '1' && dont_print != 1)
                my_putchar('X');
            j++;
        }
        if (i < hauteur - 1)
            my_putchar('\n');
        i++;
    }
}

void modif_maze(char **maze, int largeur, int hauteur)
{
    int	i = 0;
    int	j = 0;
    while (i < hauteur - 1)
        i++;
    while (j < largeur - 1)
        j++;
    if (maze[i][j - 1] == '1' && maze[i - 1][j] == '1')
        maze[i][j - 1] = '0';
    print_maze(maze, largeur, hauteur);
}
