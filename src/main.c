/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** main
*/

#include "graph.h"
#include "my.h"
#include <stdbool.h>
#include <string.h>



int main(void)
{
    graph_t *graph = init_graph();

    if (!graph)
        return EXIT_ERROR;
    move_bots(graph);
    return EXIT_SUCCESS;
}
