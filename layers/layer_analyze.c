/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** pause_layer_animation
*/

#include "game.h"

void layer_top(sfVector2i *mp, layer_t *layer, screen_t *screen)
{
    layer->b_p = sfRectangleShape_getPosition(screen->top.shape);

        if (mp->x >= layer->b_p.x && mp->x <= layer->b_p.x + \
        screen->top.size.x && mp->y >= layer->b_p.y && mp->y <= \
                                layer->b_p.y + screen->top.size.y) {
            layer->top = sfTrue;
            layer->mid = sfFalse;
                }
        else
            layer->top = sfFalse;
}

void layer_mid(sfVector2i *mp, layer_t *layer, screen_t *screen)
{
    layer->b_p = sfRectangleShape_getPosition(screen->mid.shape);

        if (mp->x >= layer->b_p.x && mp->x <= layer->b_p.x + \
            screen->mid.size.x && mp->y >= layer->b_p.y && \
            mp->y <= layer->b_p.y + screen->mid.size.y)
            layer->mid = sfTrue;
        else
            layer->mid = sfFalse;
}

void layer_bot(sfVector2i *mp, layer_t *layer, screen_t *screen)
{
    layer->b_p = sfRectangleShape_getPosition(screen->bot.shape);

        if (mp->x >= layer->b_p.x && mp->x <= layer->b_p.x + \
            screen->bot.size.x && mp->y >= layer->b_p.y && \
            mp->y <= layer->b_p.y + screen->bot.size.y)
            layer->bot = sfTrue;
        else
            layer->bot = sfFalse;
}

void layer_close(sfVector2i *mp, layer_t *layer, screen_t *screen)
{
    layer->b_p = sfRectangleShape_getPosition(screen->close.shape);

    if (mp->x >= layer->b_p.x && mp->x <= layer->b_p.x + \
        screen->close.size.x && mp->y >= layer->b_p.y && mp->y \
                            <= layer->b_p.y + screen->close.size.y)
        layer->close = sfTrue;
        else
            layer->close = sfFalse;
}

void mouse_layer(sfRenderWindow *window, game_t *game)
{
    int i = (game->init.lvl && !game->init.pause) ? 0 : 1;

    game->mp = sfMouse_getPositionRenderWindow(window);
    layer_top(&game->mp, &game->screen[i].layer, &game->screen[i]);
    layer_mid(&game->mp, &game->screen[i].layer, &game->screen[i]);
    layer_bot(&game->mp, &game->screen[i].layer, &game->screen[i]);
    layer_close(&game->mp, &game->screen[i].layer, &game->screen[i]);
}
