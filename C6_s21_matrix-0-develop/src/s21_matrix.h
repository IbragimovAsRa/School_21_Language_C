#ifndef SRC_S21_MATRIX_H
#define SRC_S21_MATRIX_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t* result);
void s21_remove_matrix(matrix_t* A);
int s21_eq_matrix(matrix_t* A, matrix_t* B);
int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_mult_number(matrix_t* A, double number, matrix_t* result);
int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_transpose(matrix_t* A, matrix_t* result);
int s21_calc_complements(matrix_t* A, matrix_t* result);
int s21_determinant(matrix_t* A, double* result);
int s21_inverse_matrix(matrix_t* A, matrix_t* result);

// Helper funсtions
matrix_t s21_cut(int rows[2], int columns[2], matrix_t A);
matrix_t s21_cut_lines(
    int cut_row, int cut_columns,
    matrix_t A);  // cut_row = -1  если строку/столбец удалять не надо
// в противном случае это номер удаляемой строки

// Support funсtions
int s21_matrix_init_helper(int rows, int columns, double* a, matrix_t* result);
// void s21_printMatrix(matrix_t a);
int s21_pow_int(int k, int exp);

#endif  // SRC_S21_MATRIX_H
