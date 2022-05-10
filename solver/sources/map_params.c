/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-alice.chaix-de-lavarene
** File description:
** instance
*/

#include "solver.h"

int adapt_map(struct request *req, char *content)
{
    int x = 0;
    int y = 0;
    for (int i = 0; content[i] && i < req->units_len; i++) {
        req->units[i] = get_unit(i, x, y, get_state(content[i]));
        if (req->units[i] == NULL)
            return (false);
        if (i != 0 && x != 0 && content[i] == '\n') {
            x = 0;
            y++;
        } else
            x++;
        req->real_len++;
    }
    return (true);
}

struct request *get_map(const char *file_name)
{
    struct request *req = malloc(sizeof(struct request));
    char *content = read_file(file_name);
    if (req == NULL || content == NULL)
        return (NULL);
    req->map_width = get_map_width(content);
    req->map_height = get_map_height(content);
    req->units_len = req->map_width * req->map_height;
    req->real_len = 0;
    if (req->units_len == 0)
        return (NULL);
    req->units = malloc(sizeof(struct unit *) * req->units_len);
    if (req->units == NULL)
        return (NULL);
    if (adapt_map(req, content) == false)
        return (NULL);
    free(content);
    return (req);
}

struct unit *get_unit(int id, int x, int y, int state)
{
    struct unit *unit = malloc(sizeof(struct unit));
    if (unit == NULL)
        return (NULL);
    unit->id = id;
    unit->x = x;
    unit->y = y;
    unit->state = state;
    unit->start = false;
    unit->end = false;
    return (unit);
}

void free_map(struct request *req)
{
    if (req->units != NULL) {
        for (int i = 0; i < req->real_len && req->units[i]; i++)
            free(req->units[i]);
        free(req->units);
    }
    free(req);
}