/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** ejected
*/

#include "game.h"

#ifndef EJECTED_H_
    #define EJECTED_H_

start_button_t create_start_button(char *title);

void animate_rect_start(sfRenderWindow *window, start_button_t *start_button);
void ejec_animation(sfRenderWindow *window , game_t *game);

#endif /* !EJECTED_H_ */
