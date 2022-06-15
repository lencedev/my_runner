/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** end_screen
*/

#include "end_screen_create.h"

static const button_settings_t end_settings[] = {
    {{150, 150}, {1000, 430}},
    {{160, 160}, {50, 430}},
};

end_screen_t create_end_screen(void)
{
    end_screen_t end_screen;

    end_screen.img_black = create_img("r/img/dead/black_screen.jpg");
    end_screen.img_blur = create_img("r/img/blur2.png");
    end_screen.img_defeat = create_img("r/img/dead/defeat_screen.png");
    end_screen.b_replay = create_button(&end_settings[0]);
    end_screen.b_leave = create_button(&end_settings[1]);
    end_screen.end_score = create_score(150, (sfVector2f){525, 250});
    return end_screen;
}

void end_score(sfRenderWindow *window, game_t *game)
{
    sfText_setString(game->end_screen.end_score.text, \
                                my_itoa(game->score.score));
    sfText_setColor(game->end_screen.end_score.text, sfRed);
    sfRenderWindow_drawText(window, game->end_screen.end_score.text, NULL);
}

void draw_end_sprite(sfRenderWindow *window , game_t *game)
{
    sfRenderWindow_drawSprite \
                (window, game->end_screen.img_blur.sprite, NULL);
    sfRenderWindow_drawSprite \
                (window, game->end_screen.img_defeat.sprite, NULL);
    sfRenderWindow_drawRectangleShape \
                (window, game->end_screen.b_leave.shape, NULL);
    sfRenderWindow_drawRectangleShape \
                (window, game->end_screen.b_replay.shape, NULL);
}

void display_end(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawSprite \
                (window, game->end_screen.img_black.sprite, NULL);
    for (int i = 12; i != 15; i++)
        bg_animation_menu(window, &game->bg[i], game->delta_time);

    draw_end_sprite(window, game);
    end_score(window, game);
}

void end(sfRenderWindow *window ,game_t *game)
{
    if (game->init.loose) {
        game->init.game = sfFalse;
        game->init.loose = sfTrue;
        game->init.m_end = sfTrue;
        sfRenderWindow_setMouseCursorVisible(window, sfTrue);
        display_end(window, game);
    }
}
