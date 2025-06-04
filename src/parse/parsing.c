/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-ayrton.ludger-crosnier
** File description:
** parsing.c
*/

#include "graph.h"
#include "my.h"
#include <string.h>

char *my_strchr(const char *str, int c)
{
    char ch = (char)c;

    while (*str != '\0') {
        if (*str == ch) {
            return (char *)str;
        }
        str++;
    }
    if (ch == '\0')
        return (char *)str;
    return NULL;
}

char *my_strtok(char *str, const char *delim)
{
    static char *last = NULL;
    char *token;

    if (str == NULL)
        str = last;
    if (str == NULL)
        return NULL;
    while (*str && my_strchr(delim, *str))
        str++;
    if (*str == '\0')
        return NULL;
    token = str;
    while (*str && !my_strchr(delim, *str))
        str++;
    if (*str) {
        *str = '\0';
        last = str + 1;
    } else
        last = NULL;
    return token;
}

void free_lines(char **lines, int count)
{
    for (int i = 0; i < count; i++)
        free(lines[i]);
    free(lines);
}

static char *get_buff(void)
{
    char *buff = malloc(sizeof(char) * (BUFFSIZE + 1));
    int size = 0;

    if (!buff)
        return NULL;
    size = read(STDIN_FILENO, buff, BUFFSIZE);
    if (size == -1) {
        free(buff);
        return NULL;
    }
    buff[size] = '\0';
    return buff;
}

static int count_lines(char *buff)
{
    int cnt = 0;
    char *tmp = my_strdup(buff);
    char *token = NULL;

    if (!tmp)
        return 0;
    token = my_strtok(tmp, "\n");
    while (token) {
        cnt++;
        token = my_strtok(NULL, "\n");
    }
    free(tmp);
    return cnt;
}

static char **get_lines(char *buff)
{
    int size = count_lines(buff);
    char **lines = malloc(sizeof(char *) * (size + 1));
    char *token = NULL;
    int cnt = 0;
    char *tmp = my_strdup(buff);

    if (!lines || size == 0 || !tmp)
        return NULL;
    token = my_strtok(tmp, "\n");
    while (token) {
        lines[cnt] = my_strdup(token);
        if (!lines[cnt])
            return NULL;
        cnt++;
        token = my_strtok(NULL, "\n");
    }
    lines[size] = NULL;
    free(tmp);
    return lines;
}

static graph_t *get_input(char *buff)
{
    graph_t *graph = malloc(sizeof(graph_t));

    if (!graph || !buff)
        return NULL;
    graph->lines = get_lines(buff);
    if (!graph->lines)
        return NULL;
    graph->rooms = malloc(sizeof(room_t *) * (count_rooms(graph->lines) + 1));
    if (!graph->rooms)
        return NULL;
    graph->rooms[count_rooms(graph->lines)] = NULL;
    return graph;
}

static int parse_rooms_doors(graph_t *graph)
{
    for (int i = 1; graph->lines[i] != NULL; i++) {
        if (graph->lines[i][0] == '#')
            continue;
        if (parse_rooms(graph->lines[i], graph, i) == SUCCESS) {
            continue;
        } else
            break;
    }
    my_dprintf(STDOUT_FILENO, "##tunnels\n");
    if (parse_door(graph) != SUCCESS)
        return EXIT_ERROR;
    return SUCCESS;
}

graph_t *parse_input(void)
{
    char *buff = get_buff();
    graph_t *graph = get_input(buff);

    if (!graph)
        return NULL;
    if (is_str_int(graph->lines[0]) != SUCCESS) {
        my_dprintf(2, "No number of robots.\n");
        return NULL;
    }
    graph->robot_nbr = my_getnbr(graph->lines[0]);
    graph->room_nbr = count_rooms(graph->lines);
    my_dprintf(1, "#number_of_robots\n%d\n#rooms\n", graph->robot_nbr);
    if (parse_rooms_doors(graph) != SUCCESS)
        return NULL;
    return graph;
}
