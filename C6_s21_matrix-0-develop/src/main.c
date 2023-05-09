#include "s21_matrix.h"


// надо ли выделять память под результат или она выделена
int main() { 
  double a[] = {2,5,7,
                6,3,4,
                 5,-2,-3};
  //double determ;
  s21_matrix_t A = s21_matrix_init_helper(3,3,a);
  s21_matrix_t B = {};
  s21_inverse_matrix (&A,&B);
//  printf("determ = %lf\n", determ);
  // s21_matrix_t B;
  // s21_calc_complements(&A, &B);


 s21_printMatrix(B);
  s21_remove_matrix(&A);
   s21_remove_matrix(&B);

  return 0; 
}