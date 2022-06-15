/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** lvl_screen
*/

#include "layers.h"

void lvl_screen(sfRenderWindow *window, game_t *game)
{
    if (game->init.lvl) {
        mouse_layer(window, game);
        layer_animation(&game->screen[0].layer);
        render_layers(window, &game->screen[0].layer, &game->screen[0]);
    }
}
