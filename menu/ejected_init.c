/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** ejec
*/

#include "game.h"

static const ejec_settings_t settings[] = {
    {"r/img/ejec/black.png", "r/img/sus/black.png", 200, 80, 0, 0},
    {"r/img/ejec/red.png", "r/img/sus/red.png" , -50, 500, 100, 0},
    {"r/img/ejec/white.png", "r/img/sus/white.png", -250, 200, 20, 0},
    {"r/img/ejec/green.png", "r/img/sus/green.png", -450, 90, 90, 0},
    {"r/img/ejec/yellow.png", "r/img/sus/yellow.png", -650, 340, 20, 0},
    {"r/img/ejec/pink.png", "r/img/sus/pink.png", -850, 200, 40, 0},
    {"r/img/ejec/cyan.png", "r/img/sus/cyan.png", -1050, 540, 20, 0},
    {"r/img/ejec/lime.png", "r/img/sus/lime.png", -1250, 45, 40, 0},
};

sprite_t create_ejec(const ejec_settings_t *settings)
{
    srand( time( NULL ) );
    float random_position_y = ((float)rand() / (float)(RAND_MAX) * 100);
    float random_position_x = ((float)rand() / (float)(RAND_MAX) * 1000);
    sprite_t ejec;
    ejec.gap = settings->x;
    sfVector2f position = {settings->x + random_position_x, \
                                settings->y + random_position_y};
    ejec.pos_def = position;
    ejec.pos = position;
    ejec.size = (sfVector2i){75, 99};
    ejec.origin = (sfVector2f){37.5, 44.5};
    ejec.id = settings->id;
    ejec.sprite = sfSprite_create();
    ejec.texture = sfTexture_createFromFile(settings->name, NULL);
    ejec.angle = settings->angle;
    sfSprite_setOrigin(ejec.sprite, ejec.origin);
    sfSprite_setRotation(ejec.sprite, ejec.angle);
    sfSprite_setTexture(ejec.sprite, ejec.texture, sfTrue);
    return ejec;
}

sprite_t *create_ejec_l(void)
{
    sprite_t *tab = malloc(sizeof(sprite_t) * 8);
    for (int i = 0; i != 8; i++)
        tab[i] = create_ejec(&settings[i]);
    return tab;
}
