/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** layers_init
*/

#include "layers.h"

static const layer_settings_t layer_settings[] = {
    {"r/img/layers/lvl.png", {0, 0}, {1200, 600}, {0, 0, 1200, 600}},
    {"r/img/layers/pause.png",{0, 0}, {1200, 600}, \
                                                {0, 0, 1200, 600}},
};

static const button_settings_t top_settings[] = {
    {{170, 80}, {510, 185}},
    {{165, 80}, {512, 200}},
};

static const button_settings_t mid_settings[] = {
    {{193, 80}, {502, 300}},
    {{310, 80}, {445, 320}},
};

static const button_settings_t bot_settings[] = {
    {{120, 80}, {535, 452}},
    {{260, 75}, {470, 452}},
};

static const button_settings_t close_settings[] = {
    {{60, 60}, {1125, 18}},
};

layer_t create_layer(const layer_settings_t setting)
{
    layer_t layer;

    layer.size = setting.size;
    layer.pos = setting.pos;
    layer.sprite = sfSprite_create();
    layer.rect_shape = setting.rect;
    layer.top = sfFalse;
    layer.mid = sfFalse;
    layer.bot = sfFalse;
    layer.close = sfFalse;
    layer.b_p = (sfVector2f){0, 0};
    layer.mp = (sfVector2i){0, 0};
    layer.texture = sfTexture_createFromFile(setting.path, NULL);

    sfSprite_setTexture(layer.sprite, layer.texture, sfTrue);
    sfSprite_setPosition(layer.sprite, layer.pos);
    sfSprite_setTextureRect(layer.sprite, layer.rect_shape);
    return layer;
}

screen_t *create_screen(void)
{
    screen_t *screen = malloc(sizeof(screen_t) * 2);

    for (int i = 0; i != 2; i++) {
        screen[i].layer = create_layer(layer_settings[i]);
        screen[i].top = create_button(&top_settings[i]);
        screen[i].mid = create_button(&mid_settings[i]);
        screen[i].bot = create_button(&bot_settings[i]);
        screen[i].close = create_button(&close_settings[0]);
    }
    return screen;
}
