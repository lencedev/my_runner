/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-owen1.bolling
** File description:
** window
*/

#include "window.h"

static const bg_settings_t bg_settings[] = {
    {"r/img/2400/1.jpg", 10},
    {"r/img/2400/2.png", 30},
    {"r/img/2400/3.png", 30},
    {"r/img/2400/4.png", 40},
    {"r/img/2400/5.png", 40},
    {"r/img/2400/6.png", 50},
    {"r/img/2400/7.png", 80},
    {"r/img/2400/8.png", 80},
    {"r/img/2400/9.png", 90},
    {"r/img/2400/10.png", 100},
    {"r/img/2400/11.png", 100},
    {"r/img/ship.png", 300},
    {"r/img/bg/2400_sb.png", 10},
    {"r/img/bg/2400_fb.png", 50},
    {"r/img/death_sus.png", 30},
};

bg_t create_bg(const bg_settings_t *settings)
{
    bg_t bg;

    bg.sprite = sfSprite_create();
    bg.texture = sfTexture_createFromFile(settings->path ,NULL);
    bg.speed = settings->speed;
    bg.boost = 0;
    bg.pos = (sfVector2f){0, 0};

    sfSprite_setTexture(bg.sprite, bg.texture, sfTrue);
    return bg;
}

bg_t *create_bg_list(void)
{
    bg_t *tab = malloc(sizeof(bg_t) * 15);

    for (int i = 0; i != 15; i++)
        tab[i] = create_bg(&bg_settings[i]);
    return tab;
}

void clock_move_bg(float delta_time, bg_t *bg)
{
        bg->pos.x -= (bg->speed + bg->boost) * delta_time;
    if (bg->pos.x <= -1200)
        bg->pos.x = 0;
    sfSprite_setPosition(bg->sprite, bg->pos);
}

void animation(sfRenderWindow *window , game_t *game)
{
    for (int i = 0; i != 12; i++) {
        if (!game->init.pause)
            clock_move_bg(game->delta_time, &game->bg[i]);
        sfRenderWindow_drawSprite(window, game->bg[i].sprite, NULL);
    }
    animate_rect(window, &game->sus, game);
    cactus_animate(window, &game->cactus_1, game);
    ennemis_animate(window, game);
    clock_boost(game);
    if (game->sus.state == JUMP)
        jump(game);
}
