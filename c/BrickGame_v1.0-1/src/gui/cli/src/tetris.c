#include "../include/tetris.h"

void init_GUI(void) {
  if (initscr() == NULL) {
    fprintf(stderr, "Unable to initialize ncurses.\n");
    exit(EXIT_FAILURE);
  }
  noecho();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  timeout(TIMEOUT);
  cbreak();

  start_color();
  init_pair(1, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(2, COLOR_BLACK, COLOR_CYAN);
  init_pair(3, COLOR_BLACK, COLOR_YELLOW);
  init_pair(4, COLOR_BLACK, COLOR_GREEN);
  init_pair(5, COLOR_BLACK, COLOR_RED);
  init_pair(6, COLOR_BLACK, COLOR_BLUE);
  init_pair(7, COLOR_BLACK, COLOR_WHITE);
}

void end_GUI(void) { endwin(); }

void gameloop(void) {
  UserAction_t user_action = NoAction;  // получаемый ввод игрока

  GameState_t state = START;  // состояние игры
  GameInfo_t info = {0};
  tetris_init();

  draw_overlay();

  int break_flag = true;
  while (break_flag) {
    /*
    START - ожидает нажатия кнопки для начала игры
    PAUSE - ожидает нажатия кнопки продолжения игры
    MOVING - движение и поворот фигуры
    GAMEOVER - ожидает начала новой игры
    */
    if (state == START || state == MOVING || state == PAUSE ||
        state == GAMEOVER) {
      user_action = get_action();
    }

    userInput(user_action, false);

    state = get_GameState();
    info = updateCurrentState();

    render_frame(info, state);

    if (state == EXIT_STATE) {
      break_flag = false;
    }

    timeout(info.speed);
    refresh();
  }

  tetris_end();
}

UserAction_t get_action(void) {
  int signal = getch();
  UserAction_t user_action = NoAction;

  switch (signal) {
    case 'S':
    case 's':
      user_action = Start;
      break;
    case 'P':
    case 'p':
      user_action = Pause;
      break;
    case 'Q':
    case 'q':
      user_action = Terminate;
      break;
    case KEY_UP:
      user_action = Up;
      break;
    case KEY_DOWN:
      user_action = Down;
      break;
    case KEY_LEFT:
      user_action = Left;
      break;
    case KEY_RIGHT:
      user_action = Right;
      break;
    case ' ':
      user_action = Action;
      break;
    default:
      user_action = NoAction;
      break;
  }

  return user_action;
}

void render_frame(GameInfo_t info, GameState_t state) {
  draw_field(info.field);
  draw_overlay();
  print_stats(info);
  draw_next(info);

  if (info.pause)
    draw_pause();
  else if (state == GAMEOVER)
    draw_gameover();
}
