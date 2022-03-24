/*
** EPITECH PROJECT, 2022
** display
** File description:
** dante
*/

#include "header.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void putstr(char *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
}

void putnbr(int nb)
{
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (nb < 10)
        my_putchar(nb + 48);
    if (nb > 9) {
        putnbr(nb / 10);
        putnbr(nb % 10);
    }
}

void display_list(lk_list **list)
{
    lk_list *temp = *list;
    int count = 0;

    while (temp != NULL) {
        putnbr(count);
        putstr(" | ");
        putnbr(temp->i);
        putstr(" ");
        putnbr(temp->j);
        putstr("\n");
        count++;
        temp = temp->next;
    }
    putstr("\n");
}
