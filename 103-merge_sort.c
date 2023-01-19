#include "sort.h"
#include <stddef.h>
#include <stdio.h>

/**
 * merge_sort - Sort an array using merge sort
 *
 * @array: The array to sort
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
int *workArray;

workArray = malloc((size) * sizeof(int));
if (size == 0 || workArray == NULL)
return;

CopyArray(array, 0, size, workArray);
TopDownSplitMerge(workArray, 0, size, array);

}

/**
 * CopyArray - copys array into work array
 *
 * @array: original array
 * @iBegin: beginning location
 * @iEnd: end location
 * @workArray: new array
 */
void CopyArray(int *array, int iBegin, int iEnd, int *workArray)
{
int k;
for (k = iBegin; k < iEnd; k++)
workArray[k] = array[k];
}

/**
 * TopDownSplitMerge - the recursive function of the merge
 *
 * @workArray: working array
 * @iBegin: beginning of array
 * @iEnd: end of array
 * @array: original array
 */
void TopDownSplitMerge(int *workArray, int iBegin, int iEnd, int *array)
{
int iMiddle;
if (iEnd - iBegin <= 1)
return;
iMiddle = (iEnd + iBegin) / 2;
/* sort both halves recursivly */
TopDownSplitMerge(array, iBegin,  iMiddle, workArray);
TopDownSplitMerge(array, iMiddle, iEnd, workArray);

TopDown(workArray, iBegin, iMiddle, iEnd, array);
}


/**
 * TopDown - Actual logic of top down merge sort
 *
 * @array: original array
 * @iBegin: beginning index
 * @iMiddle: middle index
 * @iEnd: end index
 * @workArray: working array
 */
void TopDown(int *array, int iBegin, int iMiddle, int iEnd, int *workArray)
{
int i, j, k;
i = iBegin, j = iMiddle;


for (k = iBegin; k < iEnd; k++)
{
if (i < iMiddle && (j >= iEnd || array[i] <= array[j]))
{
workArray[k] = array[i];
i = i + 1;
}
else
{
workArray[k] = array[j];
j = j + 1;
}
}
printf("Merging...\n");
printf("[left]: ");
printArray(workArray, iBegin, iMiddle);
printf("[right]: ");
printArray(workArray, iMiddle, iEnd);
printf("[Done]: ");
printArray(workArray, iBegin, iEnd);
}

/**
 * printArray - print an array with a specific format
 *
 * @array: array to print
 * @iStart: starting index
 * @iEnd: ending index
 */
void printArray(int *array, int iStart, int iEnd)
{
int i;
for (i = iStart; i < iEnd; i++)
{
if (i + 1 == iEnd)
printf("%d\n", array[i]);
else
printf("%d, ", array[i]);
}
}
