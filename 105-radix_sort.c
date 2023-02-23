#include "sort.h"
#include <stddef.h>
#include <stdio.h>
 int countSort(int *array, size_t size, int exponent);
 int getBiggest(int *array, size_t size);

/**
 * radix_sort - Sort an array using the LSD radix sort algorithm
 *
 * @array: The array to sort
 * @size: the size of the array
 */
 void radix_sort(int *array, size_t size) {
    int exp, i;
    int biggest = getBiggest(array, size);
    int biggestExp = 0;
    int powers[] = {1, 10, 100, 1000, 10000, 100000};
    for (i = 0; i <= 4; i++) {

        if (biggest / powers[i] > 0)
            biggestExp = powers[i];
    }
    
    biggestExp *= 10;
    for (exp = 10; exp <= biggestExp; exp*= 10)
    {
        countSort(array, size, exp);
    }
 }

 int countSort(int *array, size_t size, int exp) {
    int *output, i, *count;

    count = malloc(sizeof(int) * 10);
    output = malloc(sizeof(int) * size);
    if (count == NULL || output == NULL) {
        free(count);
        free(output);
        return (-1);
    }

    for (i = 0; i < (int) size; ++i) {
        ++count[((array[i] % exp) / (exp / 10))];
    }

    for (i = 1; i <= 10; ++i)
    {
        count[i] += count[i - 1];
    }


    for (i=9; i >= 0; --i) {
        output[count[((array[i] % exp)/ (exp / 10))]-1] = array[i];


        --count[((array[i] % exp)/ (exp / 10))];
    }


    for (i = 0; array[i]; ++i)
        array[i] = output[i];
    print_array(array, 10);
    return 1;

 }
 int getBiggest(int *array, size_t size) {
    int i, m = 0;
    for (i = 0; i < (int) size; i++) {
        if (array[i] > m)
            m = array[i];
    }
    return m;
 }