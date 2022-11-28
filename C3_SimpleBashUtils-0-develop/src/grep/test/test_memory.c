#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *block; // указатель для блока памяти
    int n;      // число элементов массива
    // ввод числа элементов
    printf("Size of array=");
    scanf("%d", &n);

    // выделяем память для массива
    // функция malloc возвращает указатель типа void*
    // который автоматически преобразуется в тип int*
    block = malloc(sizeof(int));

    // вводим числа в массив
    for(int i=0;i<n; i++)
    {
        printf("block[%d]=", i);
        scanf("%d", &block[i]);
    }
    printf("\n");

    // вывод введенных чисел на консоль
    for(int i=0;i<n; i++)
    {
        printf("%d \t", block[i]);
    }

    // освобождаем память
    free(block);
    return 0;
}