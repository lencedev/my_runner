/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** layers_animation
*/

#include "game.h"

void layer_animation(layer_t *layer)
{
    if (layer->top) {
        layer->rect_shape.left = 1200;
    } else
        layer->rect_shape.left = 0;
    if (layer->mid) {
        layer->rect_shape.top = 600;
    } else
        layer->rect_shape.top = 0;
    if (layer->bot) {
        layer->rect_shape.top = 600;
        layer->rect_shape.left = 1200;
    }
}

void render_layers(sfRenderWindow *window, layer_t *layer, screen_t *screen)
{

    sfSprite_setTextureRect \
    (layer->sprite, layer->rect_shape);
    sfRenderWindow_drawSprite(window, layer->sprite, NULL);
    sfRenderWindow_drawRectangleShape \
                (window, screen->top.shape, NULL);
    sfRenderWindow_drawRectangleShape \
                (window, screen->mid.shape, NULL);
    sfRenderWindow_drawRectangleShape \
                (window, screen->bot.shape, NULL);
}
