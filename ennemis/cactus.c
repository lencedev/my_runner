/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** cactus
*/

#include "game.h"

cactus_t create_cactus(char *title)
{
    cactus_t cactus;

    cactus.sprite = sfSprite_create();
    cactus.texture = sfTexture_createFromFile(title ,NULL);
    cactus.boost = 1;
    cactus.speed = 1000;
    cactus.pos = (sfVector2f){4000, 430};

    sfSprite_setTexture(cactus.sprite, cactus.texture, sfTrue);
    sfSprite_setPosition(cactus.sprite, cactus.pos);
    return cactus;
}

void clock_move_cactus(float delta_time, cactus_t *cactus)
{
        cactus->pos.x -= cactus->speed * delta_time;

    if (cactus->pos.x <= 0)
        cactus->pos.x = 4000;

    sfSprite_setPosition(cactus->sprite, cactus->pos);
}

void check_cactus_collision(cactus_t *cactus, game_t *game)
{
    sfVector2f cactus_pos = sfSprite_getPosition(cactus->sprite);

    if ((game->sus.pos.x + 75 >= cactus_pos.x && game->sus.pos.x \
            <= cactus_pos.x + 50) && (game->sus.pos.y + 99 >= cactus_pos.y \
                && game->sus.pos.y <= cactus_pos.y + 99)) {
        game->cactus_1.pos.x = 4000;
        game->score.score -= 10;
    }
}

void cactus_animate(sfRenderWindow *window, cactus_t *cactus, game_t *game)
{
    if (!game->init.pause)
        clock_move_cactus(game->delta_time, cactus);
    check_cactus_collision(cactus, game);
    sfRenderWindow_drawSprite(window, cactus->sprite, NULL);
}
