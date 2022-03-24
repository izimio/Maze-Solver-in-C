/*
** EPITECH PROJECT, 2022
** labmaker
** File description:
** dante
*/

#include "header.h"

int main(int argc, char **argv)
{
    int x;
    int y;
    int perf = 0;

    if (argc < 3)
        return (84);
    if (is_nbr(argv[1]) == 0 || is_nbr(argv[2]) == 0)
        return (84);
    if (argc > 4)
        return (84);
    if (argc == 4 && strcmp(argv[3], "perfect") != 0)
        return (84);
    else if (argc == 4 && strcmp(argv[3], "perfect") == 0)
        perf = 1;
    x = getnbr(argv[1]);
    y = getnbr(argv[2]);
    if (x <= 0 || y <= 0)
        return (84);
    generate_lab(x, y, perf);
}
