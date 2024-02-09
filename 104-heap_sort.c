#include "sort.h"

/**
 * heap_sort - sorts an arrayin ascending order using the Heap sort algorithm
 *
 * @array: array to sort
 * @size: size of array
 */
void siftDown(int key, int num[], int root, int last) {
   int bigger = 2 * root;
   while (bigger <= last) { //while there is at least one child
      if (bigger < last) //there is a right child as well; find the bigger
         if (num[bigger+1] > num[bigger]) 
            bigger++;
      //'bigger' holds the index of the bigger child
      if (key >= num[bigger]) 
          break;

      num[root] = num[bigger];
      root = bigger;
      bigger = 2 * root;
   }
   num[root] = key;
}

void heap_sort(int *num, size_t n) {
   void siftDown(int, int[], int, int);

   for (int h = n / 2; h >= 1; h--) {
      siftDown(num[h], num, h, n);
      print_array(num, n);
   }

   for (int k = n; k > 1; k--) {
      int item = num[k]; //extract current last item
      num[k] = num[1];   //move top of heap to current last node
      siftDown(item, num, 1, k-1); //restore heap properties from 1 to k-1
      print_array(num, n);

   }
}
