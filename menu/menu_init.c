/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** screen
*/

#include "ejected.h"

button_t create_button(const button_settings_t *settings)
{
    button_t button;

    button.pos = settings->pos;
    button.size = settings->size;
    button.shape = sfRectangleShape_create();
    sfColor none = {0, 0, 0, 0};

    sfRectangleShape_setSize(button.shape ,button.size);
    sfRectangleShape_setPosition(button.shape, button.pos);
    sfRectangleShape_setFillColor(button.shape, none);
    return button;
}

img_t create_img(char *title)
{
    img_t img;

    img.sprite = sfSprite_create();
    img.texture = sfTexture_createFromFile(title, NULL);
    sfSprite_setTexture(img.sprite, img.texture, sfTrue);
    return img;
}

menu_t create_menu(void)
{
    menu_t menu;

    menu.img_blur = create_img("r/img/blur2.png");
    menu.play_button = create_start_button("r/img/ejec/start.png");
    menu.play_pressed = sfFalse;
    return menu;
}
