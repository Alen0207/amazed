/*
** EPITECH PROJECT, 2025
** lib
** File description:
** strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char *str)
{
    int len;
    char *dup = NULL;

    if (!str)
        return NULL;
    len = my_strlen(str) + 1;
    dup = malloc(sizeof(char) * len);
    if (!dup)
        return NULL;
    my_strcpy(dup, str);
    return dup;
}
