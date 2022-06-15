/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** delta_time
*/

#include "game.h"

void delta_time(game_t *game, sfTime delta)
{
    delta = sfClock_getElapsedTime(game->clock_delta);
    sfClock_restart(game->clock_delta);
    game->delta_time = delta.microseconds / 1000000.0;
}
