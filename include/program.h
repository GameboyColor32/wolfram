/*
** EPITECH PROJECT, 2021
** program.h
** File description:
** main header file for the wolfram program
*/

#pragma once

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"

#define BYTE_TO_BINARY(byte) \
  (byte & 0x80 ? '*' : ' '), \
  (byte & 0x40 ? '*' : ' '), \
  (byte & 0x20 ? '*' : ' '), \
  (byte & 0x10 ? '*' : ' '), \
  (byte & 0x08 ? '*' : ' '), \
  (byte & 0x04 ? '*' : ' '), \
  (byte & 0x02 ? '*' : ' '), \
  (byte & 0x01 ? '*' : ' ') 

/**
 ** 000 001 010 011 100 101 110 111
 **/

typedef struct wolfram_s {
    char rule;
    char c;
    int line;
    int nb_chars;
    int bits;
    char *prev_gen;
    char *new_gen;
} wolfram_t;

//unit_tests
void redirect_all_std(void);

//utils.c
void help(void);
