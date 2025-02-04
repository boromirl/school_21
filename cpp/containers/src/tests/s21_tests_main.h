#ifndef S21_TESTS_MAIN_H
#define S21_TESTS_MAIN_H

#include <gtest/gtest.h>  //по факту, достаточно подключить только эту библиотеку, т.к. остальные библиотеки (см ниже), она подключит автоматически

#include <algorithm>  // std::copy, std::sort, std::swap, std::move_backward
#include <array>
#include <cstddef>           // для std::size_t
#include <initializer_list>  // std::initializer_list
#include <iostream>
#include <iterator>  // std::distance, begin, end
#include <limits>    // std::numeric_limits, std::advance
#include <list>
#include <map>
#include <memory>  // для unique_ptr
#include <queue>
#include <set>
#include <stack>
#include <stdexcept>  // std::out_of_range, std::length_error, std::logic_error, std::out_of_range
#include <string>  // для std::string - для работы со строками
#include <utility>  // для функция std::move, swap, pair, forward
#include <vector>   // begin, end

#include "../s21_containers.h"
#include "../s21_containersplus.h"

#endif