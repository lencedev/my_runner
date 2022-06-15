/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** pause_mouse
*/

#include "pause.h"

void pressed_top(game_t *game)
{
    if (game->screen[1].layer.top) {
        all_reset(game);
        resume(game);
    }
}

void pressed_mid(game_t *game)
{
    if (game->screen[1].layer.mid) {
        game->init.game = sfFalse;
        game->init.lvl = sfFalse;
        game->init.menu = sfTrue;
        game->init.pause = sfFalse;
        sfMusic_play(game->musics.menu_theme.music);
        all_reset(game);
    }
}

void pressed_bot(sfRenderWindow *window , game_t *game)
{
    if (game->screen[1].layer.bot) {
        sfRenderWindow_close(window);
    }
}

void pressed_close(game_t *game)
{
    if (game->screen[1].layer.close)
        resume(game);
}

void mouse_analyse_pause(sfRenderWindow *window , game_t *game)
{
    if (game->init.pause) {
        pressed_top(game);
        pressed_mid(game);
        pressed_bot(window ,game);
        pressed_close(game);
    }
}
