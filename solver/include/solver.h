/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-alice.chaix-de-lavarene
** File description:
** solver
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>

struct unit {
    int id;
    int x;
    int y;
    int start;
    int end;
    int state;
};

enum unit_state {
    EMPTY,
    FILL,
    USED
};

static const char units_value[3] = { '*', 'X', 'o' };
static const int exit_normal = 0;
static const int exit_fail = 84;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(const char *str);
int my_strcmp(const char *s1, const char *s2);
int string_len(char *str, char c);
struct request *get_map(const char *file_name);
struct unit *get_unit(int id, int x, int y, int state);
int adapt_map(struct request *req, char *content);
void free_map(struct request *req);
int check_file(char *content);
char *read_file(const char *file_name);
char *get_line(const char *str, const int start);
void process(struct request *req);
int find_path(struct request *req, struct unit *start, struct unit *end);
struct unit *find_nearest(struct request *req, struct unit *current,
struct unit *end);
void compute_result(struct request *req);
int get_map_width(const char *str);
int get_map_height(const char *str);
void clear_map(struct request *req);
struct unit *get_unit_by_id(const struct request *req, const int id);
int get_state(const char c);
int calc(const struct unit *start, const struct unit *end);
struct unit *clean_bucket(const struct request *req, struct unit **bucket,
const struct unit *end, const struct unit *current);
bool contain_index(int *buffer, int size, int id);

struct request {
    struct unit **units;
    int units_len;
    int real_len;
    int map_width;
    int map_height;
};

#endif /* !SOLVER_H_ */
