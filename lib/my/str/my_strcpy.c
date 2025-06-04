/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** copy an string
*/

#include <unistd.h>

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
