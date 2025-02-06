#include "../include/tetris.h"

static void clear_next();

void draw_overlay(void) {
  draw_rectangle(FRAME_START_Y, FRAME_END_Y, FRAME_START_X,
                 FRAME_END_X);  // рамка игрового поля
  // подписи для статистики справа
  mvprintw(STATS_START_Y, STATS_START_X, "STATS");
  mvprintw(SCORE_Y, STATS_START_X, "SCORE");
  mvprintw(RECORD_Y, STATS_START_X, "RECORD");
  mvprintw(NEXT_Y, STATS_START_X, "NEXT");
  mvprintw(LEVEL_Y, STATS_START_X, "LEVEL");

  print_controls();  // управление
}

void draw_rectangle(int top_y, int bottom_y, int left_x, int right_x) {
  // отрисовка углов специальными символами из ncurses
  mvaddch(top_y, left_x, ACS_ULCORNER);
  mvaddch(top_y, right_x, ACS_URCORNER);
  mvaddch(bottom_y, left_x, ACS_LLCORNER);
  mvaddch(bottom_y, right_x, ACS_LRCORNER);

  // отрисовка краев
  for (int i = (left_x + 1); i < right_x; i++) {
    mvaddch(top_y, i, ACS_HLINE);
    mvaddch(bottom_y, i, ACS_HLINE);
  }
  for (int i = (top_y + 1); i < bottom_y; i++) {
    mvaddch(i, left_x, ACS_VLINE);
    mvaddch(i, right_x, ACS_VLINE);
  }
}

void draw_field(int** field) {
  for (int i = 0; i < FIELD_HEIGHT; i++) {
    for (int j = 0; j < FIELD_WIDTH; j++) {
      if (field[i][j]) {
        attron(COLOR_PAIR(field[i][j]));
        mvaddch(FIELD_START_Y + i, FIELD_START_X + j, ACS_BLOCK);
        attroff(COLOR_PAIR(field[i][j]));
      } else {
        mvaddch(FIELD_START_Y + i, FIELD_START_X + j, '.');
      }
    }
  }
}

void draw_next(GameInfo_t info) {
  clear_next();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 6; j++) {
      if (info.next[i][j]) {
        attron(COLOR_PAIR(info.next[i][j]));
        mvaddch(PoR_Y + i, PoR_X + j, ACS_BLOCK);
        attroff(COLOR_PAIR(info.next[i][j]));
      }
    }
  }
}

static void clear_next() {
  for (int i = 0; i < NEXT_FIGURE_FIELD_HEIGHT; i++) {
    for (int j = 0; j < NEXT_FIGURE_FIELD_WIDTH; j++) {
      mvaddch(NEXT_FIGURE_START_Y + i, NEXT_FIGURE_START_X + j, ' ');
    }
  }
}

void print_stats(GameInfo_t info) {
  mvprintw(SCORE_Y + 1, STATS_START_X, "%06d", info.score);
  mvprintw(RECORD_Y + 1, STATS_START_X, "%06d", info.high_score);
  mvprintw(LEVEL_Y + 1, STATS_START_X, "%06d", info.level);
}

void print_controls(void) {
  mvprintw(0, CONTROLS_START_X + 4, "CONTROLS");
  mvprintw(2, CONTROLS_START_X, "S - start game");
  mvprintw(3, CONTROLS_START_X, "P - pause/unpause");
  mvprintw(4, CONTROLS_START_X, "Q - quit game");
  mvprintw(6, CONTROLS_START_X, "Arrows - move piece");
  mvprintw(7, CONTROLS_START_X, "SPACE  - rotate piece");
}

void draw_pause(void) {
  draw_rectangle(PAUSE_START_Y, PAUSE_START_Y + PAUSE_HEIGHT, PAUSE_START_X,
                 PAUSE_START_X + PAUSE_WIDTH);
  mvprintw(PAUSE_START_Y + 1, PAUSE_START_X + 1, "PAUSED");
}

void draw_gameover(void) {
  draw_rectangle(GAMEOVER_START_Y, GAMEOVER_START_Y + GAMEOVER_HEIGHT,
                 GAMEOVER_START_X, GAMEOVER_START_X + GAMEOVER_WIDTH);
  mvprintw(GAMEOVER_START_Y + 1, GAMEOVER_START_X + 1, " GAME ");
  mvprintw(GAMEOVER_START_Y + 2, GAMEOVER_START_X + 1, " OVER ");
}