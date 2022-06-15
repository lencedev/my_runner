/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** text
*/

#include "text.h"

void h_text(void)
{
    write(1, "\tGame Description\n", 19);
    write(1, "'My Runner!' is a Runner Game\n", 31);
    write(1, "The goal is to run as far as you can\n", 38);
    write(1, "You will have to dodge ennemis and obstacles\n", 46);
    write(1, "\tGame Settings\n", 16);
    write(1, "'./my_runner map.txt' to load the map\n", 38);
    write(1, "\tMap config :\n", 15);
    write(1, "'0' = Empty space (300 px)\n", 28);
    write(1, "'1' = Green impostor\n", 22);
    write(1, "'2' = Red impostor\n", 20);
    write(1, "'3' = Blue impostor\n", 21);
    write(1, "'4' = Pink impostor\n", 21);
    write(1, "'5' = Yellow impostor\n", 23);
    write(1, "\t'-i' to load infinite mod\n", 28);
    write(1, "Space : Jump\n", 14);
    write(1, "Escape: Leave game\n", 20);
}

void i_text(void)
{
    write(2, "\t Bad argument\n", 16);
    write(2, "Expected 'map.txt' as argument\n", 32);
    write(2, "Try '-h' to display config\n", 28);
}
