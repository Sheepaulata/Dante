/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-alice.chaix-de-lavarene
** File description:
** imperfect_maze
*/

#include <stdlib.h>
#include "generator.h"

void break_walls(char **maze, int largeur, int hauteur)
{
    int	i = 0;
    int	y = 0;
    int	x = 0;
    int	nb_walls_break = (largeur * hauteur) / 2;
    while (i < nb_walls_break)  {
        y = rand()%hauteur;
        x = rand()%largeur;
        if (maze[y][x] == '1')
            maze[y][x] = '0';
        i++;
    }
}

void gen_imparfait(int largeur, int hauteur)
{
    char **maze = malloc_maze(largeur, hauteur);
    t_dante	dante;
    init_dante(&dante, largeur, hauteur);
    if (maze == NULL)
        return ;
    maze = init_maze(maze, largeur, hauteur);
    algo_parfait(&dante, maze);
    break_walls(maze, largeur, hauteur);
    modif_maze(maze, largeur, hauteur);
}