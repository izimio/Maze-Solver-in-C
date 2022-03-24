/*
** EPITECH PROJECT, 2022
** header
** File description:
** labmaker
*/

#ifndef HEADER_H
    #define HEADER_H
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <string.h>
    typedef struct linked_list {
        int i;
        int j;
        struct linked_list *prev;
        struct linked_list *next;
    } lk_list;
    typedef struct {
        int y;
        int x;
        int perf;
    } bigstruct;
    void generate_lab(int x, int y, int perf);
    char **generate_map(int x, int y);
    char **fill_map(char **map, bigstruct *big);
    char **mine_map(bigstruct *big, int i);
    void mine_portion(char **map, int i, bigstruct *big);
    int mine(char **map, int i, int j, int x);
    void dig_last_line(char **map, int y, int x, int perf);

    // Liste //

    int getnbr(char *str);
    void my_putchar(char c);
    void putstr(char *str);
    char *creat_tab(int x);
    void free_map(char **map);
    char *fill_line(char *str, char c, int x);
    char *fill_line_alter(char *str, char c1, char c2, int x);
    void display_map(char **map, bigstruct *big);
    char **create_map(int x);
    lk_list *create_elem(int x, int y);
    int push_end(lk_list **list, int i, int j);
    void free_list(lk_list **list);
    void putnbr(int nb);
    void display_list(lk_list **list);
    void generate_lab(int x, int y, int perf);
    int is_nbr(char *str);
#endif
