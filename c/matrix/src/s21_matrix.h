#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdlib.h>

// для сравнения матриц
#define SUCCESS 1
#define FAILURE 0

// коды ошибок
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ

// заполняет все элементы матрицы одним числом
void fill_matrix(matrix_t *matr, double num);

// проверяет матрицу на корректность
int is_matrix_correct(matrix_t *matr);

// создает матрицу, в которой исключены определенные строка и столбец
void create_minor(matrix_t matr, int row, int col, matrix_t *minor);

// находит алгебраическое дополнение для элемента матрицы
double find_cofactor(matrix_t matr, int row, int col);

#endif