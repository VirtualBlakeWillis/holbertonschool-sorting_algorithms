#ifndef SORT_H
#define SORT_H
#include <stddef.h>
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);

void CopyArray(int *array, int iBegin, int iEnd, int *workArray);
void TopDownSplitMerge(int *workArray, int iBegin, int iEnd, int *array);
void TopDown(int *array, int iBegin, int iMiddle, int iEnd, int *workArray);

void printArray(int *array, int iStart, int iEnd);
#endif
