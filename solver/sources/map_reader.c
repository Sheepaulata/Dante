/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-alice.chaix-de-lavarene
** File description:
** map_reader
*/

#include <stdio.h>

#include "solver.h"

char *read_file(const char *file_name)
{
    char *buff = NULL;
    int s_size;
    int r_size;
    FILE *handler = fopen(file_name, "r");
    if (handler) {
        fseek(handler, 0, SEEK_END);
        s_size = ftell(handler);
        rewind(handler);
        buff = (char *)malloc(sizeof(char) * (s_size + 1));
        if (buff == NULL)
            return (NULL);
        r_size = fread(buff, sizeof(char), s_size, handler);
        buff[s_size] = '\0';
        if (s_size != r_size) {
            free(buff);
            return (NULL);
        }
        fclose(handler);
    }
    return (buff);
}

int find_path(struct request *req, struct unit *start, struct unit *end)
{
    struct unit *current = start;
    int turn = 0;
    start->state = USED;
    while (current->end != true) {
        current = find_nearest(req, current, end);
        if (current == NULL || turn > req->units_len)
            break;
        current->state = USED;
        if (current->end == true)
            return (true);
        turn++;
    }
    return (false);
}

char *get_line(const char *str, const int start)
{
    char *result;
    int i;
    int len = 0;

    for (i = start; i < my_strlen(str) && str[i] != '\n'; i++)
        len++;
    if (len == 0)
        return (NULL);
    result = malloc(sizeof(char) * (len + 2));
    if (result == NULL)
        return (NULL);
    for (i = start; str[i] && str[i] != '\n'; i++)
        result[i - start] = str[i];
    result[i - start] = '\0';
    return (result);
}

struct unit *find_nearest(struct request *req, struct unit *current,
    struct unit *end)
{
    const int bucket_size = 4;
    struct unit **bucket = malloc(sizeof(struct unit *) * bucket_size);
    struct unit *nearest = NULL;
    if (current->id + 1 <= req->real_len - 1 &&
        current->y == req->units[current->id + 1]->y)
        bucket[0] = get_unit_by_id(req, current->id + 1);
    else
        bucket[0] = NULL;
    if (current->id - 1 >= 0 &&
        current->y == req->units[current->id - 1]->y)
        bucket[1] = get_unit_by_id(req, current->id - 1);
    else
        bucket[1] = NULL;
    bucket[2] = get_unit_by_id(req, current->id + req->map_width + 1);
    bucket[3] = get_unit_by_id(req, current->id - (req->map_width + 1));
    nearest = clean_bucket(req, bucket, end, current);
    free(bucket);
    return (nearest);
}