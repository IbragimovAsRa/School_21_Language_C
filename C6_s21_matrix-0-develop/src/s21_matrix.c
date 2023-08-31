#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t* A, matrix_t* result) {
  int return_code = 0;
  double determ = 0;
  matrix_t tmp_matrix = {};
  s21_determinant(A, &determ);
  if (determ == 0) {
    return_code = 1;
  }
  if (return_code == 0) {
    s21_calc_complements(A, &tmp_matrix);
    s21_transpose(&tmp_matrix, result);
    s21_remove_matrix(&tmp_matrix);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = -result->matrix[i][j];
      }
    }
  }
  return return_code;
}
int s21_calc_complements(matrix_t* A, matrix_t* result) {
  int return_code = 0;
  double tmp_determ = 0;
  matrix_t tmp_matrix = {};
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      tmp_matrix = s21_cut_lines(i, j, *A);
      s21_determinant(&tmp_matrix, &tmp_determ);
      result->matrix[i][j] = tmp_determ * s21_pow_int(-1, (i + j));
      s21_remove_matrix(&tmp_matrix);
    }
  }
  return return_code;
}

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  int return_code = 0;
  if (rows <= 0 || columns <= 0) {
    return_code = 1;
  } else {
    result->columns = columns;
    result->rows = rows;
    result->matrix = malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = malloc(columns * sizeof(double));
    }
  }
  return return_code;
}

void s21_remove_matrix(matrix_t* A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);
}

int s21_eq_matrix(matrix_t* A, matrix_t* B) {
  int result = SUCCESS;
  if ((A->columns == B->columns) && (A->rows == B->rows)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (!(fabs(A->matrix[i][j] - B->matrix[i][j]) < 1e-7)) {
          result = FAILURE;
          break;
        }
      }
    }
  } else {
    result = FAILURE;
  }
  return result;
}

int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int return_code = 0;
  int rows = A->rows;
  int columns = A->columns;
  if (!((B->columns == columns) && (B->rows == rows))) {
    return_code = 1;
  } else {
    s21_create_matrix(rows, columns, result);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return return_code;
}

int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int return_code = 0;
  int rows = A->rows;
  int columns = A->columns;
  if (!((B->columns == columns) && (B->rows == rows))) {
    return_code = 1;
  } else {
    s21_create_matrix(rows, columns, result);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return return_code;
}

int s21_mult_number(matrix_t* A, double number, matrix_t* result) {
  int return_code = 0;
  int rows = A->rows;
  int columns = A->columns;

  s21_create_matrix(rows, columns, result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return return_code;
}
int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int return_code = 0;
  // Сhecking the matrix for consistency
  if (!(A->columns == B->rows)) {
    return_code = 1;
  }
  if (return_code == 0) {
    int rows_res_mat = A->rows;
    int columns_res_mat = B->columns;
    s21_create_matrix(rows_res_mat, columns_res_mat, result);
    int m = A->columns;
    for (int i = 0; i < rows_res_mat; i++) {
      for (int j = 0; j < columns_res_mat; j++) {
        result->matrix[i][j] = 0;
        // Calculating a single element
        for (int r = 0; r < m; r++) {
          result->matrix[i][j] += A->matrix[i][r] * B->matrix[r][j];
        }
      }
    }
  }
  return return_code;
}

int s21_transpose(matrix_t* A, matrix_t* result) {
  int return_code = 0;
  s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      // Calculating a single element
      result->matrix[i][j] = A->matrix[j][i];
    }
  }
  return return_code;
}

int s21_determinant(matrix_t* A, double* result) {
  int return_code = 0;
  *result = 0;
  double temp_determ = 0;
  int k = 1;
  matrix_t M;

  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else {
    for (int j = 0; j < A->rows; j++) {
      M = s21_cut_lines(0, j, *A);
      s21_determinant(&M, &temp_determ);
      *result += k * A->matrix[0][j] * temp_determ;
      k = -k;
      s21_remove_matrix(&M);
    }
  }
  return return_code;  // result;
}

matrix_t s21_cut_lines(int cut_row, int cut_columns, matrix_t A) {
  matrix_t B;
  int i_b = 0;
  int j_b = 0;
  int rows_new = A.rows;
  int columns_new = A.columns;
  if (cut_row >= 0) {
    rows_new--;
  }
  if (cut_columns >= 0) {
    columns_new--;
  }
  s21_create_matrix(rows_new, columns_new, &B);
  for (int i = 0; i < A.rows; i++) {
    if (i != cut_row) {
      for (int j = 0; j < A.columns; j++) {
        if (j != cut_columns) {
          B.matrix[i_b][j_b] = A.matrix[i][j];
          j_b++;
        }
      }
      i_b++;
    }
    j_b = 0;
  }

  return B;
}

matrix_t s21_cut(int rows[2], int columns[2], matrix_t A) {
  matrix_t B = {};
  s21_create_matrix((rows[1] - rows[0] + 1), (columns[1] - columns[0] + 1), &B);
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = A.matrix[rows[0] + i][columns[0] + j];
    }
  }
  return B;
}
// Support funсtions 1 2 3 3 2 1

int s21_matrix_init_helper(int rows, int columns, double* a, matrix_t* result) {
  s21_create_matrix(rows, columns, result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result->matrix[i][j] = a[i * columns + j];
    }
  }
  return 0;
}

// void s21_printMatrix(matrix_t a) {
//     int s = 13;
//     printf("\n");
//     printf("\n");
//     printf("+");
//     for (int f = 0; f < a.columns; f++) {
//         for (int i = 0; i < s; i++) {
//             if (i == (s - 1)) {
//                 printf("+");
//             } else {
//                 printf("-");
//             }
//         }
//         if (f == (a.columns - 1)) {
//             printf("\n");
//             printf("|");
//         }
//     }
//     for (int i = 0; i < a.rows; i++) {
//         for (int j = 0; j < a.columns; j++) {
//             printf("  ");
//             printf("%-10.3lf|", a.matrix[i][j]);
//             if (j == (a.columns - 1)) {
//                 printf("\n");
//                 printf("+");
//                 for (int f = 0; f < a.columns; f++) {
//                     for (int i = 0; i < s; i++) {
//                         if (i == (s - 1)) {
//                             printf("+");
//                         } else {
//                             printf("-");
//                         }
//                     }
//                     if (f == (a.columns - 1)) {
//                         printf("\n");
//                         if (!(a.rows - 1 == i)) {
//                             printf("|");
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     printf("\n");
//     printf("\n");
// }

int s21_pow_int(int k, int exp) {
  int result = k;
  if (exp == 0) {
    result = -k;
  } else {
    for (int i = 1; i < exp; i++) {
      result = result * k;
    }
  }
  return result;
}