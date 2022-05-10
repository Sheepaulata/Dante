/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-alice.chaix-de-lavarene
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

typedef struct	s_dante
{
    int		north;
    int		west;
    int		hauteur;
    int		largeur;
}		t_dante;

int my_getnbr(char *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void		init_dante(t_dante *dante, int largeur, int hauteur);
char		**malloc_maze(int largeur, int hauteur);
char		**init_maze(char **maze, int largeur, int hauteur);
int		good_dimensions(const char *str1, const char *str2);
int		my_strcmp(const char *str1, const char *str2);
void		gen_parfait(int largeur, int hauteur);
void		gen_imparfait(int largeur, int hauteur);
void		modif_maze(char **maze, int largeur, int hauteur);
void		algo_parfait(t_dante *dante, char **maze);


#endif /* !GENERATOR_H_ */
