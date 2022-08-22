/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main file for wolfram program
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "program.h"

void show_bit(int x)
{
    int i = 7;

    while (i >= 0) {
        printf("%c", !(x & (1u << i)) ? ' ' : '*');
        i -= 1;
    }
}

char reverse_bit(char c) {
   c = (c & 0xF0) >> 4 | (c & 0x0F) << 4;
   c = (c & 0xCC) >> 2 | (c & 0x33) << 2;
   c = (c & 0xAA) >> 1 | (c & 0x55) << 1;
   return (c);
}

static inline char get_char_from_bit(int bit, char *array)
{
    return (array[bit / 8]);
}

int get_neighbors(int bit, char *array, int nb_chars)
{
    char c = 0;
    char byte = get_char_from_bit(bit, array);
    int index = 7 - bit % 8;

    if ((byte >> index) & 1)
        c |= (1 << 1);
    if (index == 7 && bit > 0) {
        if (get_char_from_bit(bit - 1, array) & 1)
            c |= (1 << 2);
    } else if (index + 1 <= 7 && (byte >> (index + 1)) & 1)
        c |= (1 << 2);
    if (index == 0 && bit / 8 < nb_chars) {
        if (get_char_from_bit(bit + 1, array) >> 7 & 1)
            c |= 1;
    } else if (index - 1 >= 0 && (byte >> (index - 1)) & 1)
        c |= 1;
    return (c);
}

void print_wolfram(wolfram_t *wolf)
{
    if (wolf->line <= 0)
        return;
    for (int i = 0; i < wolf->nb_chars; i += 1)
        printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(wolf->prev_gen[i]));
    printf("\n");
    for (int i = 0; i < wolf->bits; i += 1) {
        if (wolf->rule >> get_neighbors(i, wolf->prev_gen, wolf->nb_chars) & 1)
            wolf->new_gen[i / 8] |= 1 << (7 - i % 8);
    }
    memcpy(wolf->prev_gen, wolf->new_gen, wolf->nb_chars);
    memset(wolf->new_gen, 0, wolf->nb_chars);
    wolf->line -= 1;
    print_wolfram(wolf);
}

int main(int ac, char **av)
{
    int opt = 0;
    wolfram_t wolf = { .rule = 0, .c = '*', .line = 5, .nb_chars = 9, .bits = 50, .prev_gen = NULL, .new_gen = NULL};

    while ((opt = getopt(ac, av, "rslwmc")) != -1) {
        switch (opt) {
        case ('r'):
            wolf.rule = (char) atoi(av[optind]);
            break;
        case ('c'):
            wolf.c = atoi(av[optind]);
            break;
        case ('l'):
            wolf.line = atoi(av[optind]);
            break;
        }
    }
    wolf.bits = wolf.line * 2 - 1;
    wolf.nb_chars = (wolf.bits / 8) + (!(wolf.bits % 8) ? 0 : 1);
    if ((wolf.prev_gen = calloc(1, sizeof(char) * wolf.nb_chars)) == NULL ||
        (wolf.new_gen = calloc(1, sizeof(char) * wolf.nb_chars)) == NULL)
        return (84);
    wolf.prev_gen[wolf.line / 8] |= (1 << (8 - wolf.line % 8));
    print_wolfram(&wolf);
    return (0);
}
