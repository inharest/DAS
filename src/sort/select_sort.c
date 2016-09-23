#include <stdio.h>
#include "util.h"
#include "test.h"

// simple select sort
void selectionSort(int arr[], int len)
{
  for (int i = 0; i < len; i++)
   {
    int k = i;
    for(int j = i+1; j < len; j++)
    {
      if(arr[k] > arr[j])
      {
        k = j;
      }
    }
    swapArray(arr, k, i);
  }
}


// heap sort

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

// test
void testSelectionSort(int arr[], int len)
{
  double start = 0, end = 0,duration = 0;
  printf("selectionSort:\n");
  start = clock();
  selectionSort(arr, len);
  end = clock();
  duration = (double)(end - start)/ CLOCKS_PER_SEC * 1000;
  printf("time: %f ms, %f s\n", duration, duration/1000);
}

void testHeapSort(int arr[], int len)
{
  double start = 0, end = 0,duration = 0;
  printf("heapSort:\n");
  start = clock();
  heapSort(arr, len);
  end = clock();
  duration = (double)(end - start)/ CLOCKS_PER_SEC * 1000;
  printf("time: %f ms, %f s\n", duration, duration/1000);
}

int main()
{
  const int len = 30;
  int* arr = NULL;
  testArray(&arr, len);
  printArray(arr, len);

  testSelectionSort(arr, len);
  printArray(arr, len);

  testHeapSort(arr, len);
  printArray(arr, len);

  return 0;
}
