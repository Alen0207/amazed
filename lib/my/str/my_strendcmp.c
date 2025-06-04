/*
** EPITECH PROJECT, 2025
** lib
** File description:
** compare end str
*/

#include "my.h"

int my_strendcmp(char *str, char *end)
{
    int len = my_strlen(str);
    int len_end = my_strlen(end);

    if (!str || !end || len < len_end)
        return FAIL;
    for (int i = len_end; i > 0; i--){
        if (str[len - i] != end[len_end - i])
            return FAIL;
    }
    return SUCCESS;
}
