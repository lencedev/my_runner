/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** map
*/

#include "input.h"

int check_input(char buf)
{
    if (buf >= 49 && buf <= 53)
        return 1;
    return 0;
}

void create_map(char *buf)
{
    int n_ennemis = 0;

    for (int i = 0; buf[i] != '\0'; i++) {
        if (check_input(buf[i]) == 1)
            n_ennemis++;
    }
    menu(n_ennemis, buf);
    return;
}

void open_file(char const *file)
{
    int fd;
    int ret;
    char buf[BUF_SIZE + 1];

    fd = open(file, O_RDONLY);

    ret = read(fd, buf, BUF_SIZE);
    buf[ret] = '\0';

    create_map(buf);
    return;
}

int user_input(char const *av)
{
    if (av[0] == '-' && av[1] == 'h' && av[2] == '\0') {
        h_text();
        return 0;
    }
    if (av[0] == '-' && av[1] == 'i' && av[2] == '\0') {
        write(1, "Infinite mod\n", 14);
        menu(2, "801000001");
        return 0;
    }
    if (av[0] == 'm' && av[1] == 'a' && av[2] == 'p')
        open_file(av);
    else {
        write(2, "error : wrong input\n", 21);
        return 84;
    }
    return 0;
}
