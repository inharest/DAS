#include <stdio.h>
#include "util.h"

void maxHeapify(int arr[], int len, int dad)
{
  int son = dad * 2 + 1;
  while(son < len)
  {
    if(son + 1 < len && arr[son] < arr[son + 1])
    {
      son++;
    }
    if(arr[dad] > arr[son])
    {
      break;
    }
    else
    {
      swapArray(arr, son, dad);
      dad = son;
      son = dad * 2 + 1;
    }
  }
}

void buildMaxHeap(int arr[], int len)
{
  for (int i = len/2 - 1; i >= 0; i--) {
    maxHeapify(arr, len, i);
  }
}

void heapSort(int arr[], int len)
{
  buildMaxHeap(arr, len);

  for (int i = len - 1; i > 0; i--) {
    swapArray(arr, 0, i);
    maxHeapify(arr, i, 0);
  }

}

void testArray(int** arrp, int len)
{
  int max = len;
  int min = 1;
  if(len > 100)
  {
    *arrp = getRandomArray(len, min, max);
  }
  else
  {
    *arrp = getRandomUniqueArray(len, min, max);
  }
}

int main()
{
  const int len = 30;
  int* arr = NULL;
  testArray(&arr, len);
  printArray(arr, len);

  heapSort(arr, len);

  printArray(arr, len);
  return 0;
}
