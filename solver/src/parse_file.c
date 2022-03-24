/*
** EPITECH PROJECT, 2022
** dante
** File description:
** parse_file
*/

#include "../include/my.h"

char *get_content(char *path, t_render *render)
{
    struct stat statbuf;
    char *content;
    int opened = open(path, O_RDONLY);

    if (opened == -1)
        exit(84);
    if (stat(path, &statbuf) == -1)
        exit(84);
    if (S_ISDIR(statbuf.st_mode))
        exit(84);
    if (!(content = malloc(sizeof(char) * statbuf.st_size + 1)))
        exit(84);
    if (read(opened, content, statbuf.st_size) == -1)
        exit(84);
    content[statbuf.st_size] = '\0';
    render->len = statbuf.st_size;
    return (content);
}

char **better_splti(char *path, t_render *render)
{
    int fd = open(path, O_RDONLY);
    char **res;
    char curr_char[1];

    res = malloc(sizeof(char *) * render->end_y + 1);
    for (int k = -1; ++k < render->end_y;)
        res[k] = 0;
    for (int y = 0; y < render->end_y; y++) {
        res[y] = malloc(render->end_x * sizeof(char) + 1);
        read(fd, res[y], render->end_x);
        res[y][render->end_x] = '\0';
        if (read(fd, curr_char, 1) != -1 && *curr_char != '\n' && *curr_char)
            exit(84);
    }
    close(fd);
    return (res);
}

void check_lab(t_render *render, char *s, int i)
{
    int e = 0;
    int k = 0;
    int trig = 0;

    for (; s[++i]; e++) {
        if (s[i] != 'X' && s[i] != '*' && s[i] != '\n')
            exit(84);
        if (s[i] == '\n') {
            render->end_y++;
            render->end_x = (trig == 0 ? i : render->end_x);
            trig = 1;
        }
        if (k != 0 && ((e != k && s[i] == '\n') || (e + 1 != k && !s[i + 1])))
            exit(84);
        k = ((s[i] == '\n' || !s[i + 1]) && k == 0) ? e + 1 : k;
        e = (s[i] == '\n') ? 0 : e;
    }
    if (render->end_y == 1)
        render->end_x = i;
}
