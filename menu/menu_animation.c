/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** menu_animation
*/

#include "ejected.h"

void clock_move_menu(float delta_time, bg_t *bg)
{
    bg->pos.x += bg->speed * delta_time;

    if (bg->pos.x >= 0)
        bg->pos.x = -1200;
    sfSprite_setPosition(bg->sprite, bg->pos);
}

void bg_animation_menu(sfRenderWindow *window, bg_t *bg, float s)
{
    clock_move_menu(s, bg);
    sfRenderWindow_drawSprite(window, bg->sprite, NULL);
}

void animate_menu(sfRenderWindow *window , game_t *game)
{
    if (game->init.menu || game->init.lvl) {
        bg_animation_menu(window, &game->bg[12], game->delta_time);
        bg_animation_menu(window, &game->bg[13], game->delta_time);
        ejec_animation(window, game);
        sfRenderWindow_drawSprite(window, game->menu.img_blur.sprite, NULL);
        if (game->init.menu)
            animate_rect_start(window, &game->menu.play_button);
    }
}
