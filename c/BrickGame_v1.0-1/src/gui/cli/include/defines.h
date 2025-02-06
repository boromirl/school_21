#ifndef FRONTEND_DEFINES_H
#define FRONTEND_DEFINES_H

#define FIELD_HEIGHT 20
#define FIELD_WIDTH 10

// игровое поле
#define FIELD_START_X 2
#define FIELD_START_Y 2
#define FIELD_END_X (FIELD_START_X + FIELD_WIDTH - 1)
#define FIELD_END_Y (FIELD_START_Y + FIELD_HEIGHT - 1)

// рамка вокруг игрового поля
#define FRAME_START_X 1
#define FRAME_START_Y 1
#define FRAME_END_X (FRAME_START_X + FIELD_WIDTH + 1)
#define FRAME_END_Y (FRAME_START_Y + FIELD_HEIGHT + 1)

// начало поля статистики
#define STATS_START_X 18
#define STATS_START_Y 0

// пункты статистики
#define SCORE_Y 2
#define RECORD_Y 5
#define LEVEL_Y 13

// плашка паузы
#define PAUSE_START_Y (FIELD_START_Y + 8)
#define PAUSE_START_X (FIELD_START_X + 1)
#define PAUSE_HEIGHT 2
#define PAUSE_WIDTH 7

// плашка GAME OVER
#define GAMEOVER_START_Y (FIELD_START_Y + 8)
#define GAMEOVER_START_X (FIELD_START_X + 1)
#define GAMEOVER_HEIGHT 3
#define GAMEOVER_WIDTH 7

// поле со следующей фигурой
#define NEXT_Y 8
#define NEXT_FIGURE_FIELD_WIDTH 6
#define NEXT_FIGURE_FIELD_HEIGHT 4
#define NEXT_FIGURE_START_X 18
#define NEXT_FIGURE_START_Y 9
#define NEXT_FIGURE_END_X (NEXT_FIGURE_START_X + NEXT_FIGURE_FIELD_WIDTH - 1)
#define NEXT_FIGURE_END_Y (NEXT_FIGURE_START_Y + NEXT_FIGURE_FIELD_HEIGHT - 1)

// точка отсчета внутри поля следующей фигуры (для прорисовки фигуры)
#define PoR_X 19
#define PoR_Y 10

// Управление
#define CONTROLS_START_X 30

#define TIMEOUT 1000

// цвета ncurses
#define BLUE 1
#define RED 2
#define CYAN 3
#define YELLOW 4
#define MAGENTA 5
#define GREEN 6
#define WHITE 7

#endif