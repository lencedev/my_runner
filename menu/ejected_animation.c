/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** ejected_init
*/

#include "game.h"

void move_ejec(float delta, sprite_t *ejec)
{
    srand( time( NULL ) );
    float random_pos_y = ((float)rand() / (float)(RAND_MAX) * 500);
    float random_pos_x = ((float)rand() / (float)(RAND_MAX) * 150);

        ejec->pos.x += delta * 35;
    if (ejec->pos.x >= 1250) {
        ejec->pos.x = -50 - random_pos_x;
        ejec->pos.y = 20 + random_pos_y;
    }
    sfSprite_setPosition(ejec->sprite, ejec->pos);
}

void rotate_ejec(float delta, sprite_t *ejec)
{
    srand( time( NULL ) );
    float random_number = ((float)rand() / (float)(RAND_MAX) * 0.2);

        ejec->angle -= (delta * 9) + random_number;
        sfSprite_setRotation(ejec->sprite, ejec->angle);
}

void animate_ejec(sfRenderWindow *window, sprite_t *ejec, float delta)
{
    move_ejec(delta, ejec);
    rotate_ejec(delta, ejec);
    sfRenderWindow_drawSprite(window, ejec->sprite, NULL);
}

void ejec_animation(sfRenderWindow *window , game_t *game)
{
    for (int i = 0; i != 8; i++)
        animate_ejec(window, &game->ejecs[i], game->delta_time);
}
