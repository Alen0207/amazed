/*
** EPITECH PROJECT, 2025
** amzed
** File description:
** compute distance
*/

#include "graph.h"

static int min_dist_index(int *distances, bool *is_in_short, int nb_rooms)
{
    int min = distances[0];
    int index = 0;

    for (int i = 1; i < nb_rooms; i++){
        if (!is_in_short[i] && distances[i] <= min){
            min = distances[i];
            index = i;
        }
    }
    return index;
}

static void change_distance(int *distances, bool *is_in_short, graph_t *graph)
{
    int min_index = min_dist_index(distances, is_in_short, graph->room_nbr);

    is_in_short[min_index] = true;
    for (int j = 0; j < graph->room_nbr; j++){
        if (!is_in_short[j] && graph->doors[min_index][j] &&
            distances[min_index] != INF &&
            distances[min_index] + graph->doors[min_index][j] < distances[j])
            distances[j] = distances[min_index] + graph->doors[min_index][j];
    }
}

int *compute_dist_from(graph_t *graph, int current)
{
    int *distances = malloc(sizeof(int) * (graph->room_nbr + 1));
    bool *is_in_short = malloc(sizeof(bool) * (graph->room_nbr + 1));

    for (int i = 0; i < graph->room_nbr; i++){
        distances[i] = INF;
        is_in_short[i] = false;
    }
    distances[current] = 0;
    for (int i = 0; i < graph->room_nbr; i++){
        change_distance(distances, is_in_short, graph);
    }
    return distances;
}
