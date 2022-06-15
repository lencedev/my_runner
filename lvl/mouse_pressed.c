/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** mouse_pressed
*/

#include "mouse.h"

void pressed_normal(game_t *game)
{
    if (game->screen[0].layer.top) {
        game->ennemis_1.speed = 1000;
        game->cactus_1.speed = 1000;
        game->init.hardcore = sfFalse;
    }
}

void pressed_hardcore(game_t *game)
{
    if (game->screen[0].layer.mid) {
        game->cactus_1.speed = 1150;
        for (int i = 0; i != game->nb_ennemis; i++)
            game->ennemis_list[i].speed = 1150;
        game->init.hardcore = sfTrue;
    }
}

void pressed_close_lvl(game_t *game)
{
    if (game->screen[0].layer.close) {
        game->init.lvl = sfFalse;
        game->init.menu = sfTrue;
        all_reset(game);
    }
}

void mouse_analyse_lvl(game_t *game)
{
    if (!game->init.menu) {
        if (game->screen[0].layer.bot) {
            game->init.game = sfTrue;
            sfMusic_stop(game->musics.menu_theme.music);
            game->once_music.music_game = 1;
        }
        pressed_normal(game);
        pressed_hardcore(game);
        pressed_close_lvl(game);
    }
}
