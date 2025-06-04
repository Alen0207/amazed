/*
** EPITECH PROJECT, 2025
** heade
** File description:
** preoject
*/

#ifndef AMAZED_H_
    #define AMAZED_H_
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #define INF __INT_MAX__
    #define MAX_NAME_LEN    256
    #define MAX_ROOMS       1024
    #define MAX_LINES       10000
    #define BUFFSIZE        10000

typedef struct room_s {
    char *name;
    int x;
    int y;
    int is_start;
    int is_end;
    int is_occuped;
    int distance_from_end;
    int nbr;
} room_t;

typedef struct robot_s {
    int curr_room;
    bool is_arrived;
} robot_t;

typedef struct graph_s {
    int lines_nbr;
    int robot_nbr;
    robot_t **robots;
    int room_nbr;
    room_t **rooms;
    char **lines;
    int **doors;
} graph_t;

char *my_strtok(char *str, const char *delim);
char *my_strchr(const char *str, int c);

int count_rooms(char **lines);
int parse_rooms(char *line, graph_t *graph, int i);
graph_t *parse_input(void);
void move_bots(graph_t *graph);
int *compute_dist_from(graph_t *graph, int current);
int parse_door(graph_t *graph);
robot_t **create_robot_arr(int nb_robots, int start_room);
void free_robots(robot_t **robots, int nb_robot);
graph_t *init_graph(void);

#endif /* AMAZED_H_ */
