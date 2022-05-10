/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-alice.chaix-de-lavarene
** File description:
** perfect_maze
*/

#include <stdlib.h>
#include "generator.h"

void change_north_west(char **maze, int i, int j, t_dante *dante)
{
    if (i - 1 >= 0 && maze[i - 1][j] == '1')
        dante->north = 1;
    if (j - 1 >= 0 && maze[i][j - 1] == '1')
        dante->west = 1;
}

void one_wall_aside(char **maze, int i, int j, t_dante *dante)
{
    if (i - 1 >= 0 && dante->north == 1 && dante->west == 0)
        maze[i - 1][j] = '0';
    if (j - 1 >= 0 && dante->north == 0 && dante->west == 1)
        maze[i][j - 1] = '0';
}

void two_walls_aside(char **maze, int i, int j, int random)
{
    random = rand()%2;
    if (j - 1 >= 0 && random == 0)
        maze[i][j - 1] = '0';
    else if (i - 1 >= 0 && random == 1)
        maze[i - 1][j] = '0';
}

void algo_parfait(t_dante *dante, char **maze)
{
    int	i = 0;
    int	j;
    int	random = 0;
    while (i < dante->hauteur) {
        j = 0;
        dante->north = 0;
        dante->west = 0;
        while (j < dante->largeur) {
            if (i == 0)
                maze[i][j] = '0';
            change_north_west(maze, i, j, dante);
            one_wall_aside(maze, i, j, dante);
            if (dante->north == 1 && dante->west == 1)
                two_walls_aside(maze, i, j, random);
            j += 2;
        }
        i += 2;
    }
}

void gen_parfait(int largeur, int hauteur)
{
    t_dante	dante;
    char **maze = malloc_maze(largeur, hauteur);

    init_dante(&dante, largeur, hauteur);
    if (maze == NULL)
        return ;
    maze = init_maze(maze, largeur, hauteur);
    algo_parfait(&dante, maze);
    modif_maze(maze, largeur, hauteur);
}
