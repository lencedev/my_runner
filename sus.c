/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** sus
*/

#include "game.h"

rect_t create_rectangle(char *title)
{
    rect_t rect;

    rect.size = (sfVector2f){75, 99};
    rect.pos = (sfVector2f){200,425};
    rect.sprite = sfSprite_create();
    rect.rect_shape = (sfIntRect){0, 0, 75, 99};
    rect.clock_animation = sfClock_create();
    rect.clock_boost = sfClock_create();
    rect.boost = 0;
    rect.state = WALK;
    rect.timer = 0;
    rect.texture = sfTexture_createFromFile(title, NULL);
    sfSprite_setTexture(rect.sprite, rect.texture, sfTrue);
    sfSprite_setPosition(rect.sprite, rect.pos);
    return rect;
}

void clock_animation(float seconds, rect_t *sus)
{
    if (seconds > 0.05) {
        sus->rect_shape.left += 75;
        sfClock_restart(sus->clock_animation);

        if (sus->rect_shape.left >= 900) {
            sus->rect_shape.left = 0;
            sfClock_restart(sus->clock_animation);
        }
    }
}

void animate_rect(sfRenderWindow *window, rect_t *sus, game_t *game)
{
    sfTime time = sfClock_getElapsedTime(sus->clock_animation);
    float seconds = time.microseconds / 1000000.0;

    if (!game->init.pause)
        clock_animation(seconds, sus);
    sfSprite_setTextureRect(sus->sprite, sus->rect_shape);
    sfRenderWindow_drawSprite(window, sus->sprite, NULL);
}
