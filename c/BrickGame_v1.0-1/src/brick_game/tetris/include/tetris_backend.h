#ifndef TETRIS_BACKEND_H
#define TETRIS_BACKEND_H

#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "defines.h"
#include "fsm.h"
#include "objects.h"

// Функции для связи с интерфейсом
void userInput(UserAction_t action, bool hold);
GameInfo_t updateCurrentState(void);
GameState_t get_GameState(void);

// Функции инициализации и завершения
void tetris_init(void);
void tetris_end(void);
void game_info_init(void);

// полное зачищение матрицы игрового поля
void clear_field(void);

void act(UserAction_t action, Tetris_t* tetris);
void calculate_coords(Figure_t* figure);
void place_figure(Figure_t figure, int** field);
void rotate_figure(Figure_t* figure);
void check_and_move(Figure_t* figure, int** field, int direction);
void move_figure(Figure_t* figure, int y, int x);
void zero_tetris();
void destroy_complete_rows(int** field);
void destroy_row(int** field, int row);
void drop_row(int** field, int row);
void drop_figure(Tetris_t* tetris);
void add_points_for_rows(int number_of_complete_rows, int* score);
void set_level(int score, int* level);
void set_speed(int level, int* speed);

int count_complete_rows(int** field);
int get_high_score();
void set_high_score(int new_high_score, int* current_high_score);

// Функции проверок (check.c)
bool is_visible(int y, int x);
bool is_touching(Figure_t figure, int** field);
bool are_complete_rows(int** field);
bool is_row_complete(int** field, int row);
bool is_collision(Figure_t figure, int** field);
bool is_in_field(int y, int x);

// Функции получения фигур
void get_shape(int id, int orientation, int** shape);
void get_color_matrix(int id, int orientation, int** matrix);

#endif