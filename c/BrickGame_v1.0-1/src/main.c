#include <time.h>

#include "gui/cli/include/tetris.h"

int main(void) {
  /*
  нужно для инициализации seed для функции rand(), иначе он всегда равен 1.
  Требуется только один раз вызвать srand, а дальше просто использовать rand
  */
  srand(time(NULL));

  init_GUI();
  gameloop();
  end_GUI();
  return 0;
}
