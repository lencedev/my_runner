/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** pause
*/

#include "game.h"

#ifndef PAUSE_H_
    #define PAUSE_H_

void all_reset(game_t *game);
void pause_game(sfRenderWindow *window, game_t *game);
void resume(game_t *game);

#endif /* !PAUSE_H_ */
