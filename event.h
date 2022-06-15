/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** event
*/

#include "game.h"

#ifndef EVENT_H_
    #define EVENT_H_

void mouse_analyse_lvl(game_t *game);
void mouse_analyse_pause(sfRenderWindow *window, game_t *game);
void mouse_layer_pause(sfRenderWindow *window, game_t *game);
void mouse_analyse_ejec(sfRenderWindow *window, game_t *game);
void all_reset(game_t *game);
void resume(game_t *game);

#endif /* !EVENT_H_ */
