/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** create robots array
*/


#include "graph.h"

void free_robots(robot_t **robots, int nb_robot)
{
    for (int i = 0; i < nb_robot; i++)
        free(robots[i]);
    free(robots);
}

static robot_t *create_robot(int start_room)
{
    robot_t *robot = malloc(sizeof(robot_t));

    if (!robot)
        return NULL;
    robot->curr_room = start_room;
    robot->is_arrived = false;
    return robot;
}

robot_t **create_robot_arr(int nb_robots, int start_room)
{
    robot_t **robots = malloc(sizeof(robot_t *) * (nb_robots + 1));

    if (!robots)
        return NULL;
    for (int i = 0; i < nb_robots; i++){
        robots[i] = create_robot(start_room);
        if (!robots[i]){
            free_robots(robots, i);
            return NULL;
        }
    }
    return robots;
}
