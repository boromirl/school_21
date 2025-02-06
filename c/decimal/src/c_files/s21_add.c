#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int return_code =
      0;  // инициализация кода возврата нулем (0 - успешное выполнение)
  s21_big_decimal big_value_1, big_value_2,
      big_result;  // переменные биг децимал для промежуточных вычислений

  // переводим числа в рабочий формат и зануляем результат (на всякий случай)
  decimal_to_big(value_1, &big_value_1);
  decimal_to_big(value_2, &big_value_2);
  zero_big_decimal(&big_result);

  // приводим числа к одному scale
  normalize(&big_value_1, &big_value_2);
  big_result.scale = big_value_1.scale;

  // если у чисел одинаковый знак записываем его в результат
  if (big_value_1.sign == big_value_2.sign) big_result.sign = big_value_1.sign;
  // если знаки разные и первое число больше
  else if (s21_is_greater_number(big_value_1, big_value_2)) {
    // берем знак от первого числа и переводим второе в дополнительную форму
    big_result.sign = big_value_1.sign;
    make_bid_decimal_compliment(&big_value_2);
  }
  // иначе (если второе число больше первого)
  else {
    // берем знак от второго числа и переводим первое в дополнительную форму
    big_result.sign = big_value_2.sign;
    make_bid_decimal_compliment(&big_value_1);
  }

  // Складываем каждый int (x + доп. y == x - y)
  add_big_bits(big_value_1, big_value_2, &big_result);

  // если число не влезает в мантиссу
  if (big_result.bits[3] != 0) {
    // обработка переполнения 3-го битса. Функция будет делить число на 10, пока
    // scale не дойдет до нуля или число не влезет в мантиссу
    handle_high_overflow(&big_result);
  }

  if (is_big_zero(big_result)) big_result.sign = 0;

  // если результат влезает
  if (does_big_fit_into_decimal(big_result)) {
    // перевод результата в децимал
    big_to_decimal(big_result, result);
    return_code = 0;
  }
  // если не влезает и положительно -> слишком большое число
  else if (big_result.sign == 0) {
    return_code = 1;
  }
  // если не влезает и отрицательно -> слишком маленькое число
  else if (big_result.sign == 1) {
    return_code = 2;
  }

  return return_code;
}