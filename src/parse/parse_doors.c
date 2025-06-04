/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-ayrton.ludger-crosnier
** File description:
** parse_doors.c
*/

#include "graph.h"
#include "my.h"


static int is_door_line(char *line)
{
    char *name_one = NULL;
    char *name_two = NULL;
    char *tmp = my_strdup(line);

    if (!tmp)
        return EXIT_ERROR;
    name_one = my_strtok(tmp, "-");
    name_two = my_strtok(NULL, "-");
    if (name_one && name_two) {
        free(tmp);
        return SUCCESS;
    }
    free(tmp);
    return EXIT_ERROR;
}

static int count_doors(char **lines)
{
    int cnt = 0;

    for (int i = 0; lines[i] != NULL; ++i)
        if (is_door_line(lines[i]) == SUCCESS)
            cnt++;
    return cnt;
}

static void get_door_coords(graph_t *graph, char *name_one, char *name_two)
{
    int x = 0;
    int y = 0;

    for (int i = 0; graph->rooms[i] != NULL; ++i) {
        if (my_strcmp(graph->rooms[i]->name, name_one) == 0) {
            x = graph->rooms[i]->nbr;
            continue;
        }
        if (my_strcmp(graph->rooms[i]->name, name_two) == 0) {
            y = graph->rooms[i]->nbr;
            continue;
        }
    }
    graph->doors[x][y] = 1;
    graph->doors[y][x] = 1;
}

static int get_door(graph_t *graph, char *line)
{
    char *name_one = NULL;
    char *name_two = NULL;
    char *tmp = my_strdup(line);

    if (!tmp)
        return EXIT_ERROR;
    name_one = my_strtok(tmp, "-");
    name_two = my_strtok(NULL, "-");
    get_door_coords(graph, name_one, name_two);
    return SUCCESS;
}

static int get_doors(graph_t *graph, char *line)
{
    if (is_door_line(line) == SUCCESS) {
        if (get_door(graph, line) != SUCCESS)
            return EXIT_ERROR;
        my_dprintf(STDOUT_FILENO, "%s\n", my_strtok(line, " \n\0"));
    }
    return SUCCESS;
}

int parse_door(graph_t *graph)
{
    int nbr = count_rooms(graph->lines);

    graph->doors = malloc(sizeof(int *) * nbr);
    if (!graph->doors)
        return EXIT_ERROR;
    for (int i = 0; i < nbr; ++i) {
        graph->doors[i] = malloc(sizeof(int) * nbr);
        if (!graph->doors[i])
            return EXIT_ERROR;
        for (int j = 0; j < nbr; ++j)
            graph->doors[i][j] = 0;
    }
    for (int i = 0; graph->lines[i] != NULL; ++i)
        if (get_doors(graph, graph->lines[i]) != SUCCESS)
            return EXIT_ERROR;
    return SUCCESS;
}
