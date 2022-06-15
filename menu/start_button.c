/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** start_button
*/

#include "ejected.h"

start_button_t create_start_button(char *title)
{
    start_button_t start_button;

    start_button.size = (sfVector2f){75, 99};
    start_button.pos = (sfVector2f){200, 430};
    start_button.sprite = sfSprite_create();
    start_button.rect_shape = (sfIntRect){0, 0, 400, 150};
    start_button.clock_animation = sfClock_create();
    start_button.clock_move = sfClock_create();
    start_button.clock_gravity = sfClock_create();
    start_button.velocity = 30;
    start_button.is_pressed = sfFalse;
    start_button.texture = sfTexture_createFromFile(title, NULL);


    sfSprite_setTexture(start_button.sprite, start_button.texture, sfTrue);
    sfSprite_setPosition(start_button.sprite, start_button.pos);
    sfSprite_setTextureRect(start_button.sprite, start_button.rect_shape);
    return start_button;
}

void clock_animation_start(float seconds, start_button_t *start_button)
{
    if (seconds > 0.1) {
        start_button->rect_shape.left += 400;
        sfClock_restart(start_button->clock_animation);

        if (start_button->rect_shape.left >= 4800) {
            start_button->rect_shape.left = 0;
            sfClock_restart(start_button->clock_animation);
        }
    }
}

void clock_move_start_button(float seconds, start_button_t *start_button)
{
    static int sign = 1;

    if (seconds > 0.01) {
        start_button->pos.x = start_button->pos.x + sign * 0.8;
        start_button->pos.y = 100 * sin(start_button->pos.x / 70) + 220;
        sfSprite_setPosition(start_button->sprite, start_button->pos);
        sfClock_restart(start_button->clock_move);
        if (sign == 1 && start_button->pos.x >= 850) {
            sign = -1;
        } else if (sign == -1 && start_button->pos.x <= -50) {
            sign = 1;
        }
    }
}

void animate_rect_start(sfRenderWindow *window, start_button_t *start_button)
{
    sfTime time = sfClock_getElapsedTime(start_button->clock_animation);
    float seconds = time.microseconds / 1000000.0;
    sfTime time_move = sfClock_getElapsedTime(start_button->clock_move);
    float seconds_move = time_move.microseconds / 1000000.0;

    clock_move_start_button(seconds_move, start_button);
    clock_animation_start(seconds, start_button);
    sfSprite_setTextureRect(start_button->sprite, start_button->rect_shape);
    sfRenderWindow_drawSprite(window, start_button->sprite, NULL);
}
