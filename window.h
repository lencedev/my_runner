/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** window
*/

#include "game.h"

#ifndef WINDOW_H_
    #define WINDOW_H_

void animate_rect(sfRenderWindow *window, rect_t *sus, game_t *game);
void cactus_animate(sfRenderWindow *window, cactus_t *cactus, game_t *game);
void ennemis_animate(sfRenderWindow *window, game_t *game);
void jump(game_t *game);
void clock_boost(game_t *game);

#endif /* !WINDOW_H_ */
