/*
** EPITECH PROJECT, 2022
** dante
** File description:
** astar_main
*/

#include "include/my.h"

int main(int argc, char *argv[])
{
    if (argc == 2)
        return (astar_core(argv));
    else
        return 84;
    return (0);
}
