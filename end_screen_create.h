/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** end_screen_create
*/

#include "game.h"

#ifndef END_SCREEN_CREATE_H_
    #define END_SCREEN_CREATE_H_

button_t create_button(const button_settings_t *settings);
score_t create_score(int size, sfVector2f pos);
img_t create_img(char *title);

void bg_animation_menu(sfRenderWindow *window, bg_t *bg, float s);
char *my_itoa(int nb);

#endif /* !END_SCREEN_CREATE_H_ */
