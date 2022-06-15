/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** pause
*/

#include "layers.h"

void pause_music(game_t *game)
{
    if (!game->init.hardcore)
        sfMusic_pause(game->musics.game_theme.music);
    else
        sfMusic_pause(game->musics.hardcore_theme.music);

    sfMusic_pause(game->musics.sus_walking.music);

    return;
}

void pause_game(sfRenderWindow *window, game_t *game)
{
    if (game->init.game && game->init.pause) {
        pause_music(game);
        mouse_layer(window, game);
        layer_animation(&game->screen[1].layer);
        render_layers(window, &game->screen[1].layer, &game->screen[1]);
    }
    return;
}

void resume(game_t *game)
{
    game->init.pause = sfFalse;

    if (!game->init.hardcore)
        sfMusic_play(game->musics.game_theme.music);
    else
        sfMusic_play(game->musics.hardcore_theme.music);

    sfMusic_play(game->musics.sus_walking.music);
    return;
}
