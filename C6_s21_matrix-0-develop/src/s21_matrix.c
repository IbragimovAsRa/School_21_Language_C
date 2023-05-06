#include "s21_matrix.h"

int s21_calc_complements(s21_matrix_t* A, s21_matrix_t* result) {
  int return_code = 0;
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0;i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = s21_calc_determinant(s21_cut_lines(i,j, *A))*s21_pow_int(-1, (i + j));

    }
  }
  return return_code;
}

int s21_create_matrix(int rows, int columns, s21_matrix_t* result) {
  int return_code = 0;
  result->columns = columns;
  result->rows = rows;
  result->matrix = malloc(rows * sizeof(double*));
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = malloc(columns * sizeof(double));
  }
  return return_code;
}

void s21_remove_matrix(s21_matrix_t* A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);
}

int s21_eq_matrix(s21_matrix_t* A, s21_matrix_t* B) {
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

int s21_sum_matrix(s21_matrix_t* A, s21_matrix_t* B, s21_matrix_t* result) {
  int return_code = 0;
  int rows = A->rows;
  int columns = A->columns;
  if (!((B->columns == columns) && (B->rows == rows) &&
        (result->rows == rows) && (result->columns == columns))) {
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

int s21_sub_matrix(s21_matrix_t* A, s21_matrix_t* B, s21_matrix_t* result) {
  int return_code = 0;
  int rows = A->rows;
  int columns = A->columns;
  if (!((B->columns == columns) && (B->rows == rows) &&
        (result->rows == rows) && (result->columns == columns))) {
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

int s21_mult_number(s21_matrix_t* A, double number, s21_matrix_t* result) {
  int return_code = 0;
  int rows = A->rows;
  int columns = A->columns;
  if (!((result->rows == rows) && (result->columns == columns))) {
    return_code = 0;
  } else {
    s21_create_matrix(rows, columns, result);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return return_code;
}

int s21_mult_matrix(s21_matrix_t* A, s21_matrix_t* B, s21_matrix_t* result) {
  int return_code = 0;
  // Сhecking the matrix for consistency
  if (!(A->columns == B->rows)) {
    return_code = 0;
  }
  if (return_code == 0) {
    int rows_res_mat = A->rows;
    int columns_res_mat = B->columns;
    int m = A->columns;
    for (int i = 0; i < rows_res_mat; i++) {
      for (int j = 0; j < columns_res_mat; j++) {
        // Calculating a single element
        for (int r = 0; r < m; r++) {
          result->matrix[i][j] += A->matrix[i][r] * B->matrix[r][j];
        }
      }
    }
  }
  return return_code;
}

int s21_transpose(s21_matrix_t* A, s21_matrix_t* result) {
  int return_code = 0;
  s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      // Calculating a single element
      result->matrix[i][j] += A->matrix[j][i];
    }
  }
  return return_code;
}

double  s21_calc_determinant(s21_matrix_t A) {
  // int return_code = 0;
  double result = 0;
  int k = 1;
  s21_matrix_t M;

  if (A.rows == 1) {
    result = A.matrix[0][0];
  } else {
    for (int j = 0; j < A.rows; j++) {
      M = s21_cut_lines(0, j, A);
      result += k*A.matrix[0][j] * s21_calc_determinant(M);
      k = -k;
      s21_remove_matrix(&M);
    }
  }
  return result; // return_code;  // result;
}

s21_matrix_t s21_cut_lines(int cut_row, int cut_columns, s21_matrix_t A) {
  s21_matrix_t B;
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

s21_matrix_t s21_cut(int rows[2], int columns[2], s21_matrix_t A) {
  s21_matrix_t B = {};
  s21_create_matrix((rows[1] - rows[0] + 1), (columns[1] - columns[0] + 1), &B);
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = A.matrix[rows[0] + i][columns[0] + j];
    }
  }
  return B;
}
// Support funсtions 1 2 3 3 2 1

s21_matrix_t s21_matrix_init_helper(int rows, int columns, double* a) {
  s21_matrix_t result = {};
  s21_create_matrix(rows, columns, &result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result.matrix[i][j] = a[i * columns + j];
    }
  }
  return result;
}

void s21_printMatrix(s21_matrix_t a) {
  int s = 13;
  printf("\n");
  printf("\n");
  printf("+");
  for (int f = 0; f < a.columns; f++) {
    for (int i = 0; i < s; i++) {
      if (i == (s - 1)) {
        printf("+");
      } else {
        printf("-");
      }
    }
    if (f == (a.columns - 1)) {
      printf("\n");
      printf("|");
    }
  }
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      printf("  ");
      printf("%-10.3lf|", a.matrix[i][j]);
      if (j == (a.columns - 1)) {
        printf("\n");
        printf("+");
        for (int f = 0; f < a.columns; f++) {
          for (int i = 0; i < s; i++) {
            if (i == (s - 1)) {
              printf("+");
            } else {
              printf("-");
            }
          }
          if (f == (a.columns - 1)) {
            printf("\n");
            if (!(a.rows - 1 == i)) {
              printf("|");
            }
          }
        }
      }
    }
  }
  printf("\n");
  printf("\n");
}

int s21_pow_int(int k, int exp) {
  int result = k;
  for (int i = 1; i < exp; i++) {
    result = result * k;
  }
  return result;
}