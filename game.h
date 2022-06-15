/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-owen1.bolling
** File description:
** game
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

#ifndef GAME_H_
    #define GAME_H_

    #define WALK    0
    #define JUMP    1

typedef struct bg_t {
    float speed;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    float boost;
} bg_t;

typedef struct button_t {
    sfVector2f size;
    sfRectangleShape *shape;
    sfVector2f pos;

} button_t;

typedef struct button_settings_t {
    sfVector2f size;
    sfVector2f pos;
} button_settings_t;

typedef struct img_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} img_t;

typedef struct cactus_t {
    char *title;
    float speed;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f size;
    sfVector2f pos;
    int runner_speed;
    float boost;
    float seconds;
    sfTime time;
} cactus_t;

typedef struct rect_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect_shape;
    sfClock *clock_animation;
    sfClock *clock_boost;
    sfVector2f pos;
    sfVector2f size;
    float boost;
    int state;
    float timer;
} rect_t;

typedef struct start_button_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect_shape;
    sfClock *clock_animation;
    sfClock *clock_gravity;
    sfClock *clock_rotate;
    sfClock *clock_move;
    sfVector2f pos;
    sfVector2f size;
    float velocity;
    sfBool is_pressed;
} start_button_t;

typedef struct menu_t {
    img_t img_blur;
    start_button_t play_button;
    sfBool play_pressed;
} menu_t;

typedef struct init_t {
    sfBool alive;
    sfBool loose;
    sfBool game;
    sfBool menu;
    sfBool lvl;
    sfBool is_walking;
    sfBool m_game;
    sfBool m_end;
    sfBool hardcore;
    sfBool pause;
} init_t;

typedef struct score_t {
    sfText *text;
    sfFont *font;
    int size;
    int score;
    int temp_score;
    int best;
    float boost;
    float timer;
} score_t;

typedef struct music_t {
    sfMusic *music;
    char *title;
} music_t;

typedef struct all_music_t {
    music_t menu_theme;
    music_t game_theme;
    music_t hardcore_theme;
    music_t sus_walking;
    music_t sus_jump;
    music_t end_theme;
} all_music_t;

typedef struct layer_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect_shape;
    sfVector2f pos;
    sfVector2f size;
    sfVector2i mp;
    sfVector2f b_p;
    sfBool top;
    sfBool mid;
    sfBool bot;
    sfBool close;
} layer_t;

typedef struct screen_t {
    layer_t layer;
    button_t top;
    button_t mid;
    button_t bot;
    button_t close;
} screen_t;

typedef struct ejec_settings_t {
    char *name;
    char *id;
    int x;
    int y;
    float angle;
    int rank;
} ejec_settings_t;

typedef struct bg_settings_t {
    char *path;
    int speed;
} bg_settings_t;

typedef struct layer_settings_t {
    char *path;
    sfVector2f pos;
    sfVector2f size;
    sfIntRect rect;
} layer_settings_t;

typedef struct ennemis_settings_t {
    char *path;
} ennemis_settings_t;

typedef struct ennemis_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect_shape;
    sfClock *clock_animation;
    sfClock *clock_boost;
    sfVector2f pos;
    sfVector2f def_pos;
    sfVector2f size;
    float boost;
    float speed;
    float timer;
    sfBool inf;
} ennemis_t;

typedef struct sprite_t {
    char *title;
    char *id;
    int gap;
    float nb;
    float speed;
    float angle;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2i size;
    sfVector2f pos;
    sfVector2f pos_def;
    sfVector2f origin;
    sfVector2f size_2;
} sprite_t;

typedef struct once_music_t {
    int music_menu;
    int music_game;
    int music_end;
} once_music_t;

typedef struct end_screen_t {
    button_t b_replay;
    button_t b_leave;
    img_t img_black;
    img_t img_defeat;
    img_t img_blur;
    score_t end_score;
} end_screen_t;

typedef struct game_t {
    cactus_t cactus_1;
    ennemis_t ennemis_1;
    ennemis_t *ennemis_list;
    rect_t sus;
    score_t score;
    menu_t menu;
    init_t init;
    all_music_t musics;
    sprite_t *ejecs;
    bg_t *bg;
    sfVector2f *tab_pos;
    end_screen_t end_screen;
    screen_t *screen;
    float delta_time;
    sfClock *clock_delta;
    once_music_t once_music;
    sfVector2i mp;
    int nb_ennemis;
    score_t best_score;
} game_t;

#endif /* !GAME_H_ */
