/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** create_graph
*/

#include "graph.h"
#include "my.h"



graph_t *init_graph(void)
{
    graph_t *graph = parse_input();
    int start_room = FAIL;
    int *dist = NULL;

    if (!graph)
        return NULL;
    for (int i = 0; i < graph->room_nbr; i++){
        if (graph->rooms[i]->is_start)
            start_room = i;
    }
    for (int i = 0; i < graph->room_nbr; i++){
        if (graph->rooms[i]->is_end)
            dist = compute_dist_from(graph, i);
    }
    graph->robots = create_robot_arr(graph->robot_nbr, start_room);
    for (int i = 0; i < graph->room_nbr; i++)
        graph->rooms[i]->distance_from_end = dist[i];
    return graph;
}
