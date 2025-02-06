#include "s21_tetris_test.h"

int main(void) {
  int total = 0;
  int failed = 0;

  Suite *tests[] = {
      suite_boolean_checks(),
      suite_fsm(),
      suite_backend(),
      NULL,
  };

  printf("\n\n\tTESTS\n\n");
  for (Suite **current = tests; *current; current++) {
    SRunner *sr = srunner_create(*current);
    srunner_set_fork_status(sr, CK_FORK);
    srunner_run_all(sr, CK_NORMAL);

    total += srunner_ntests_run(sr);
    failed += srunner_ntests_failed(sr);

    srunner_free(sr);
  }

  printf("\n" GRAY_BG WHITE " total: %d " RESET GREEN_BG WHITE
         " success: %d " RESET RED_BG WHITE " failed: %d " RESET "\n",
         total, total - failed, failed);

  return failed == 0 ? 0 : 1;
}