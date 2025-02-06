#ifndef TETRIS_H
#define TETRIS_H

#include <locale.h>
#include <ncurses.h>

#include "../../../brick_game/tetris/include/tetris_backend.h"
#include "defines.h"  // в этом файле определены значения #define

// инициализация интерфейса
void init_GUI(void);
// завершение работы с интерфейсом
void end_GUI(void);
// основной цикл
void gameloop(void);
// получение пользовательского ввода
UserAction_t get_action(void);

// прорисовка кадра
void render_frame(GameInfo_t info, GameState_t state);

// Функции отрисовки
void draw_overlay(void);
void draw_rectangle(int top_y, int bottom_y, int left_x, int right_x);
void draw_field(int** field);
void draw_next(GameInfo_t info);
// Прописывание значений статистики (очки, уровень, и т.д.)
void print_stats(GameInfo_t info);
void print_controls(void);
void draw_pause(void);
void draw_gameover(void);

#endif