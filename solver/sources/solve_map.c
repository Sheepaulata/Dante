/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-alice.chaix-de-lavarene
** File description:
** engine
*/

#include "solver.h"

void compute_result(struct request *req)
{
    char *result = malloc(sizeof(char) * (req->real_len + 2));
    int i = 0;
    if (result == NULL)
        return;
    for (; i < req->real_len && req->units[i]; i++)
        if (req->units[i]->state < 0)
            result[i] = '\n';
        else
            result[i] = units_value[req->units[i]->state];
    result[i++] = '\0';
    write(1, result, req->real_len + 2);
    free(result);
}

void process(struct request *req)
{
    struct unit *start = req->units[0];
    struct unit *end =  req->units[req->real_len - 1];
    int call = false;
    if (start == NULL || end == NULL)
    return;
    if (end->state != EMPTY || start->state != EMPTY) {
        my_putstr("no solution found\n");
        return;
    }
    for (int i = 0; i < req->map_width * req->map_height * 4; i++) {
        clear_map(req);
        call = find_path(req, start, end);
        if (call == 0 && i + 1 >=
            req->map_width * req->map_height * 4) {
            my_putstr("no solution found\n");
            return;
        } else if (call == true)
            break;
    }
    compute_result(req);
}
