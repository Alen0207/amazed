/*
** EPITECH PROJECT, 2025
** move_bots
** File description:
** amazed
*/

#include "graph.h"
#include "my.h"

static int find_closest_room(graph_t *graph, int current)
{
    int min = INF;
    int min_index = FAIL;

    for (int i = 0; i < graph->room_nbr; i++){
        if (graph->doors[current][i] &&
            graph->rooms[i]->distance_from_end < min &&
            !graph->rooms[i]->is_occuped && !graph->rooms[i]->is_start){
                min = graph->rooms[i]->distance_from_end;
                min_index = i;
            }
    }
    return min_index;
}

void move_bot_to(graph_t *graph, int robot_index, int next)
{
    int old = graph->robots[robot_index]->curr_room;

    graph->rooms[old]->is_occuped = 0;
    graph->robots[robot_index]->curr_room = next;
    if (!graph->rooms[next]->is_end)
        graph->rooms[next]->is_occuped = 1;
    if (graph->rooms[next]->is_end)
        graph->robots[robot_index]->is_arrived = 1;
    my_dprintf(STDOUT_FILENO, "P%d-%s",
        robot_index + 1, graph->rooms[next]->name);
}

void move_to_next(graph_t *graph)
{
    int closest_room = -1;

    for (int i = 0; i < graph->robot_nbr; i++){
        if (graph->robots[i]->is_arrived)
            continue;
        closest_room = find_closest_room(graph, graph->robots[i]->curr_room);
        if (closest_room == FAIL){
            continue;
        }
        move_bot_to(graph, i, closest_room);
        if (i != graph->robot_nbr - 1)
            my_dprintf(STDOUT_FILENO, " ");
    }
    my_dprintf(STDOUT_FILENO, "\n");
}

static int all_robots_arrived(graph_t *graph)
{
    for (int i = 0; i < graph->robot_nbr; i++){
        if (!graph->robots[i]->is_arrived){
            return FAIL;
        }
    }
    return SUCCESS;
}

void move_bots(graph_t *graph)
{
    my_dprintf(STDOUT_FILENO, "#moves\n");
    while (all_robots_arrived(graph) == FAIL) {
        move_to_next(graph);
    }
}
