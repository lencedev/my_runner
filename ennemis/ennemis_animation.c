/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** ennemis
*/

#include "game.h"

void clock_animation_ennemis(float delta_time, ennemis_t *ennemis)
{
    ennemis->timer = ennemis->timer + (delta_time * 10);
    if (ennemis->timer > 0.5) {
        ennemis->rect_shape.left += 75;
        ennemis->timer = 0;
        if (ennemis->rect_shape.left >= 450) {
            ennemis->rect_shape.left = 0;
        }
    }
}

void clock_move_ennemis(float delta_time, ennemis_t *ennemis)
{
    srand( time( NULL ) );
    float random_number = ((float)rand() / (float)(RAND_MAX) * 400);

        ennemis->pos.x -= (ennemis->speed) * delta_time;
    if (ennemis->pos.x <= 0 && ennemis->inf)
        ennemis->pos.x = 2500 + random_number;

    sfSprite_setTextureRect(ennemis->sprite, ennemis->rect_shape);
    sfSprite_setPosition(ennemis->sprite, ennemis->pos);
}

void check_ennemis_collision(ennemis_t *ennemis, game_t *game)
{
    sfVector2f ennemis_pos = sfSprite_getPosition(ennemis->sprite);
    if ((game->sus.pos.x + 75 >= ennemis_pos.x && game->sus.pos.x <= \
            ennemis_pos.x + 50) && (game->sus.pos.y + 99 >= ennemis_pos.y \
                                && game->sus.pos.y <= ennemis_pos.y + 99)) {
        game->init.alive = sfFalse;
        game->init.loose = sfTrue;
    }
}

void ennemis_animate(sfRenderWindow *window, game_t *game)
{
    for (int i = 0; i != game->nb_ennemis; i++ ) {
        if (!game->init.pause && game->ennemis_list[i].pos.x > 0) {
            clock_move_ennemis(game->delta_time, &game->ennemis_list[i]);
            clock_animation_ennemis(game->delta_time, &game->ennemis_list[i]);
            check_ennemis_collision(&game->ennemis_list[i], game);
        }
        if (game->ennemis_list[i].pos.x > 0)
            sfRenderWindow_drawSprite(window, game->ennemis_list[i].sprite, \
                                                                        NULL);
    }
}
