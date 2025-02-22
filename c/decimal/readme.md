# Decimal

## Сборка

* Сборка осуществляется при помощи `Makefile`. Цели:
    * `make` или  `make all` или `s21_decimal.a` - компиляция статической библиотеки `s21_decimal.a`
    * `make clean` - очистка временных файлов
    * `make test` - компиляция и запуск тестов `(!! Требуется библиотека check !!)`
    * `make gcov_report` - отчет о покрытии тестами (создается папка `report`, отчет можно открыть через `report/index.html`)

## Описание

* В этом проекте реализуется библиотека `s21_decimal.h` на языке программирования `С`. Эта библиотека добавляет возможность работы с типом `decimal`, который отсутствует в стандарте языка.
* Тип `Decimal` представляет десятичные числа в диапазоне от положительных `79,228,162,514,264,337,593,543,950,335` до отрицательных `79,228,162,514,264,337,593,543,950,335`.
* `Decimal` число — это значение с плавающей точкой, состоящее из знака, числового значения, где каждая цифра находится в диапазоне от 0 до 9, и коэффициента масштабирования, который указывает положение десятичной точки, разделяющей целые и дробные части числового значения.
* Двоичное представление `Decimal` состоит из 1-разрядного знака, 96-разрядного целого числа и коэффициента масштабирования, используемого для деления целого числа и указания того, какая его часть является десятичной дробью. Коэффициент масштабирования неявно равен числу 10, возведенному в степень в диапазоне от 0 до 28.
* `Decimal` число реализовано в виде четырехэлементного массива 32-разрядных целых чисел со знаком (int bits[4];). (однако для обработки переполнения при операциях используется `int64`)
* bits[0], bits[1], и bits[2] содержат младшие, средние и старшие 32 бита 96-разрядного целого числа соответственно.
* bits[3] содержит коэффициент масштабирования и знак, и состоит из следующих частей:
    * Биты от 0 до 15, младшее слово, не используются и равны нулю.
    * Биты с 16 по 23 содержат показатель степени от 0 до 28, который указывает степень 10 для разделения целого числа.
    * Биты с 24 по 30 не используются и равны нулю.
    * Бит 31 содержит знак; 0 означает положительный, а 1 означает отрицательный.

* Реализованы следующие функции для работы с `decimal`:
    * Арифметические операции (сложение, вычитание, умножение, деление)
    * Операторы сравнения (<, <=, >, >=, ==, !=)
    * Преобразователи (из int, из float, в int, в float)
    * `floor` - округляет указанное `Decimal` число до ближайшего целого числа в сторону отрицательной бесконечности
    * `round` - округляет `Decimal` до ближайшего целого числа
    * `truncate` - возвращает целые цифры указанного `Decimal` числа; любые дробные цифры отбрасываются, включая конечные нули 
    * `negate` - возвращает результат умножения указанного `Decimal` на -1
    
## Участники проекта:
    
* `boromirl`
* `sabresha`
* `didiobel`
* `varlymic` 