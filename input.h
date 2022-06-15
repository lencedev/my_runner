/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** input
*/

#define BUF_SIZE 4000

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef INPUT_H_
    #define INPUT_H_

void menu(int n_ennemis, char *buf);
void h_text(void);
int check_input(char buf);

#endif /* !INPUT_H_ */
