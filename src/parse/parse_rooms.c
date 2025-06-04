/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-ayrton.ludger-crosnier
** File description:
** parse_rooms.c
*/

#include "my.h"
#include "graph.h"
#include <string.h>

static int is_room_line(char *line)
{
    char *name = NULL;
    char *x = NULL;
    char *y = NULL;
    char *tmp = my_strdup(line);

    if (!tmp)
        return EXIT_ERROR;
    name = my_strtok(tmp, " ");
    x = my_strtok(NULL, " ");
    y = my_strtok(NULL, " ");
    if (name && x && y && is_str_int(x) == SUCCESS &&
        is_str_int(y) == SUCCESS) {
        free(tmp);
        return SUCCESS;
    }
    free(tmp);
    return EXIT_ERROR;
}

int count_rooms(char **lines)
{
    int cnt = 0;

    for (int i = 0; lines[i] != NULL; ++i)
        if (is_room_line(lines[i]) == SUCCESS)
            cnt++;
    return cnt;
}

static int parse_room(graph_t *graph, char *line, int i)
{
    char *tmp = my_strdup(line);
    char *name = my_strtok(tmp, " \t");
    char *x_str = my_strtok(NULL, " \t");
    char *y_str = my_strtok(NULL, " \t");

    graph->rooms[i] = malloc(sizeof(room_t));
    if (!graph->rooms[i] || !tmp || !x_str || !y_str)
        return EXIT_ERROR;
    graph->rooms[i]->is_start = 0;
    graph->rooms[i]->is_end = 0;
    graph->rooms[i]->name = my_strdup(name);
    if (!graph->rooms[i]->name) {
        free(tmp);
        return EXIT_ERROR;
    }
    graph->rooms[i]->x = my_getnbr(x_str);
    graph->rooms[i]->y = my_getnbr(y_str);
    graph->rooms[i]->nbr = i;
    free(tmp);
    return SUCCESS;
}

int parse_rooms(char *line, graph_t *graph, int i)
{
    static int cnt = 0;

    if (is_room_line(line) == SUCCESS) {
        if (parse_room(graph, line, cnt) != SUCCESS)
            return EXIT_ERROR;
        if (!my_strcmp(graph->lines[i - 1], "##start")) {
            graph->rooms[cnt]->is_start = 1;
            my_dprintf(STDOUT_FILENO, "##start\n");
        }
        if (!my_strcmp(graph->lines[i - 1], "##end")) {
            graph->rooms[cnt]->is_end = 1;
            my_dprintf(STDOUT_FILENO, "##end\n");
        }
        my_dprintf(STDOUT_FILENO, "%s %d %d\n", graph->rooms[cnt]->name,
            graph->rooms[cnt]->x, graph->rooms[cnt]->y);
        cnt++;
        return SUCCESS;
    }
    return EXIT_ERROR;
}
