/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** boost
*/

#include "game.h"

void speed_boost(game_t *game)
{
    for (int i = 0; i != 12; i++) {
        game->bg[i].boost = game->bg[i].boost + 5;
    }
    game->ennemis_1.speed = game->ennemis_1.speed + 10;
    game->sus.boost += 10;
    game->cactus_1.boost = game->cactus_1.boost + 10;
    game->score.boost += 0.5;
}

void clock_boost(game_t *game)
{
    game->sus.timer += game->delta_time;
    if (game->sus.timer > 6 && !game->init.loose) {
        speed_boost(game);
        game->sus.timer = 0;
    }
}
