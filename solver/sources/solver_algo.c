/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-alice.chaix-de-lavarene
** File description:
** solver_alogo
*/

#include "solver.h"

int calc(const struct unit *start, const struct unit *end)
{
    double res = sqrt((start->x - end->x) *
(start->x - end->x) + (start->y - end->y) * (start->y - end->y));
    return ((int)res);
}

bool contain_index(int *buffer, int size, int id)
{
    for (int i = 0; i < size; i++)
        if (buffer[i] == id)
            return (true);
    return (false);
}

struct unit *clean_bucket(const struct request *req, struct unit **bucket,
const struct unit *end, const struct unit *current)
{
    static int *buffer = NULL;
    static int index = 0;
    const int bucket_size = 4;
    int dist = INT_MAX;
    struct unit *nearest = NULL;
    int len = 0;
    if (buffer == NULL)
        buffer = malloc(sizeof(int) * req->real_len);
    for (int i = 0; i < bucket_size; i++) {
        if (bucket[i] == NULL || bucket[i]->state != EMPTY ||
        !(bucket[i]->id >= 0 && bucket[i]->id <= req->real_len - 1)
        || contain_index(buffer, index, bucket[i]->id))
            continue;
        if (bucket[i]->end == true)
            return (bucket[i]);
        if (calc(bucket[i], end) < dist ||
        (calc(bucket[i], end) <= dist
        && rand() % 2 == 1)) {
            dist = calc(bucket[i], end);
            nearest = bucket[i];
        }
        len++;
    }
    if (len > 1) {
        buffer[index] = current->id;
        index++;
    }
    return (nearest);
}
