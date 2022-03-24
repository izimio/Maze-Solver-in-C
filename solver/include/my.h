/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** oui
*/

#ifndef _MY_H_
    #define _MY_H_
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    typedef struct s_point {
        int x;
        int y;
    } t_point;
    typedef struct s_lst {
        int x;
        int y;
        int ori;
        int g;
        struct s_lst *bef;
        struct s_lst *next;
    } t_lst;
    typedef struct s_render {
        t_lst *open;
        t_lst *close;
        int end_x;
        int end_y;
        int len;
        char **map;
        char *map_row;
        char **cp_map;
    } t_render;
    int my_abs(int a);
    void check_lab(t_render *render, char *s, int i);
    char **better_splti(char *path, t_render *render);
    void print_map(char **res, t_render *render);
    char *get_content(char *path, t_render *render);
    int check_n_add_op(t_render *render, int x, int y, t_lst *daddy);
    char **my_split(char *str, char *charset);
    t_render *init_struct(char *file);
    t_lst *create_elem(int x, int y, int ori, t_lst *bef);
    void my_pushback(t_lst **b_l, t_lst *elem);
    void push_front(t_lst **lst, t_lst *new);
    t_lst *my_node_pop(t_lst **begin_list, int nb);
    void add_to_close(t_render *render);
    void add_to_open(t_render *render, int x, int y, t_lst *daddy);
    int astar_core(char **argv);
#endif
