#ifndef SRC_S21_MATRIX_H
#define SRC_S21_MATRIX_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct s21_matrix_struct {
  double** matrix;
  int rows;
  int columns;
} s21_matrix_t;

int s21_create_matrix(int rows, int columns, s21_matrix_t* result);
void s21_remove_matrix(s21_matrix_t* A);
int s21_eq_matrix(s21_matrix_t* A, s21_matrix_t* B);
int s21_sum_matrix(s21_matrix_t* A, s21_matrix_t* B, s21_matrix_t* result);
int s21_sub_matrix(s21_matrix_t* A, s21_matrix_t* B, s21_matrix_t* result);
int s21_mult_number(s21_matrix_t* A, double number, s21_matrix_t* result);
int s21_mult_matrix(s21_matrix_t* A, s21_matrix_t* B, s21_matrix_t* result);
int s21_transpose(s21_matrix_t* A, s21_matrix_t* result);
int s21_calc_complements(s21_matrix_t* A, s21_matrix_t* result);


// Helper funсtions
double s21_calc_determinant(s21_matrix_t A);
s21_matrix_t s21_cut(int rows[2], int columns[2], s21_matrix_t A);
s21_matrix_t s21_cut_lines(int cut_row, int cut_columns,
                          s21_matrix_t A); // cut_row = -1  если строку/столбец удалять не надо
                          // в противном случае это номер удаляемой строки 

// Support funсtions
s21_matrix_t s21_matrix_init_helper(int rows, int columns, double* a);
void s21_printMatrix(s21_matrix_t a);
int s21_pow_int(int k, int exp);
#endif  // SRC_S21_MATRIX_H
