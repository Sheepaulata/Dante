/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-alice.chaix-de-lavarene
** File description:
** map
*/

#include "solver.h"

int get_map_width(const char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\n')
            return (i);
    return (0);
}

int get_map_height(const char *str)
{
    return (string_len(str, '\n') + 2);
}

void clear_map(struct request *req)
{
    struct unit *start = req->units[0];
    struct unit *end =  req->units[req->real_len - 1];
    start->start = true;
    end->end = true;
    for (int i = 0; i < req->real_len; i++)
        if (req->units[i]->state == USED)
        req->units[i]->state = EMPTY;
}

struct unit *get_unit_by_id(const struct request *req, const int id)
{
    if (id >= 0 && id < req->real_len)
        return (req->units[id]);
    return (NULL);
}

int get_state(const char c)
{
    const int state_len = 3;
    for (int i = 0; i < state_len; i++)
        if (units_value[i] == c)
            return (i);
    return (-1);
}