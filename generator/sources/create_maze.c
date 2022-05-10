/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-alice.chaix-de-lavarene
** File description:
** create_maze
*/

#include <stdlib.h>
#include "generator.h"

char **malloc_maze(int largeur, int hauteur)
{
    int	i = 0;
    int	max_larg = largeur + (largeur - 1);
    int	max_haut = hauteur + (hauteur - 1);
    char **maze = malloc(sizeof(char *) * (max_haut + 1));
    if (largeur == 0 || hauteur == 0)
        return (NULL);
    if (maze == NULL) {
        return (NULL);
    }
    while (i < max_haut) {
        maze[i] = malloc(sizeof(char) * (max_larg + 1));
        if (maze[i] == NULL)
            return (NULL);
        i++;
    }
    maze[i] = NULL;
    return (maze);
}

char **init_maze(char **maze, int largeur, int hauteur)
{
    int	i = 0;
    int	j = 0;
    while (i < hauteur + (hauteur - 1)) {
        j = 0;
        while (j < largeur + (largeur - 1)) {
            if (j % 2 == 0 && i % 2 == 0)
                maze[i][j] = '0';
            else if (j % 2 != 0 && i % 2 == 0)
                maze[i][j] = '1';
            else if (i % 2 != 0)
                maze[i][j] = '1';
        j++;
        }
    maze[i][j] = '\0';
    i++;
    }
    return (maze);
}

void init_dante(t_dante *dante, int largeur, int hauteur)
{
    dante->north = 0;
    dante->west = 0;
    dante->largeur = largeur + (largeur - 1);
    dante->hauteur = hauteur + (hauteur - 1);
}