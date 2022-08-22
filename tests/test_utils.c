/*
** EPITECH PROJECT, 2021
** test_utils.c
** File description:
** file for testing the utility file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
