/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** ennemis_init
*/
#include "input.h"
#include "game.h"

static const ennemis_settings_t set[] = {
    {"r/img/green.png"},
    {"r/img/red.png"},
    {"r/img/blue.png"},
    {"r/img/pink.png"},
    {"r/img/yellow.png"},
};

ennemis_t create_ennemis(const ennemis_settings_t *set, sfVector2f pos, \
                                                                sfBool inf)
{
    ennemis_t ennemis;

    ennemis.speed = 1000;
    ennemis.pos = pos;
    ennemis.def_pos = pos;
    ennemis.size = (sfVector2f){75, 99};
    ennemis.sprite = sfSprite_create();
    ennemis.rect_shape = (sfIntRect){0, 0, 75, 99};
    ennemis.clock_animation = sfClock_create();
    ennemis.boost = 1;
    ennemis.timer = 0;
    ennemis.inf = inf;
    ennemis.texture = sfTexture_createFromFile(set->path, NULL);

    sfSprite_setTexture(ennemis.sprite, ennemis.texture, sfTrue);
    sfSprite_setPosition(ennemis.sprite, ennemis.pos);
    sfSprite_setTextureRect(ennemis.sprite, ennemis.rect_shape);
    return ennemis;
}

int ennemis_color(char buf)
{
    for (int i = 0; i != 6; i++) {
        if (buf == i + '0')
        return i - 1;
    }
    return 0;
}

ennemis_t *create_ennemis_list(int n_ennemis, char *buf)
{
    ennemis_t *ennemis_list = malloc(sizeof(ennemis_t) * n_ennemis);
    int nb = 1000;
    int y = 0;
    sfBool inf_active = (buf[0] == '8') ? sfTrue : sfFalse;

    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == '0')
            nb += 300;
        else if (check_input(buf[i]) == 1) {
            ennemis_list[y] = create_ennemis(&set[ennemis_color(buf[i])], \
                                (sfVector2f){nb, 435}, inf_active);
            y++;
        }
        else if (!inf_active)
            write(2, "wrong map input\n", 17);
    }
    return ennemis_list;
}