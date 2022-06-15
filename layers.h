/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** layers
*/

#include "game.h"

#ifndef LAYERS_H_
    #define LAYERS_H_

button_t create_button(const button_settings_t *settings);
void mouse_layer(sfRenderWindow *window, game_t *game);
void render_layers(sfRenderWindow *window, layer_t *layer, screen_t *screen);
void layer_animation(layer_t *layer);

#endif /* !LAYERS_H_ */
