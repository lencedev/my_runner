/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** reset
*/

#include "game.h"

void boost_reset(game_t *game)
{
    game->sus.boost = 0;
    game->cactus_1.boost = 1;
    game->ennemis_1.boost = 1;
    game->score.boost = 1;
}

void all_reset(game_t *game)
{
    for (int i = 0; i != 13; i++) {
        game->bg[i].pos = (sfVector2f){0, 0};
        game->bg[i].boost = 0;
    }
    for (int i = 0; i != game->nb_ennemis; i++) {
        game->ennemis_list[i].pos.x = game->ennemis_list[i].def_pos.x;
    }
    game->sus.pos.y = 425;
    game->cactus_1.pos.x = 4000;
    game->ennemis_1.pos.x = 2500;
    game->score.score = 0;
    game->screen[0].layer.bot = sfFalse;
    game->screen[0].layer.close = sfFalse;

    sfSprite_setPosition(game->sus.sprite, game->sus.pos);
    boost_reset(game);
}
