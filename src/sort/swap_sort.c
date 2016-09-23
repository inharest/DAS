#include <stdio.h>
#include "util.h"
#include "test.h"

// simple swap srot
// bubble sort
void bubbleSort(int arr[], int len)
{
  for (int i = 0; i < len; i++)
   {
    for (int j = 0; j < len - i - 1; j++)
    {
      if(arr[j] > arr[j+1])
      {
         swapArray(arr,j,j+1);
      }
    }
  }
}

// quick sort
void quickSort(int arr[], int i, int j)
{
  if (i >= j)
		return;
  int mid = i;
  int low = i + 1;
  int high = j;
  while (low<high) {
    while(low<high && arr[low] < arr[mid])
    {
      low++;
    }
    while(low<high && arr[high] > arr[mid])
    {
      high--;
    }
    swapArray(arr,low,high);
  }
  if(arr[mid] > arr[high])
  {
    swapArray(arr,high,mid);
  }
  else
  {
    high--;
  }
  quickSort(arr, i, high);
  quickSort(arr, high+1, j);
}

// test
void testBubbleSort(int arr[], int len)
{
  double start = 0, end = 0,duration = 0;
  printf("bubbleSort:\n");
  start = clock();
  bubbleSort(arr, len);
  end = clock();
  duration = (double)(end - start)/ CLOCKS_PER_SEC * 1000;
  printf("time: %f ms, %f s\n", duration, duration/1000);
}

void testQuickSort(int arr[], int len)
{
  double start = 0, end = 0,duration = 0;
  printf("quickSort:\n");
  start = clock();
  quickSort(arr, 0, len-1);
  end = clock();
  duration = (double)(end - start)/ CLOCKS_PER_SEC * 1000;
  printf("time: %f ms, %f s\n", duration, duration/1000);
  //printArray(arr, len);
}

int main()
{
  int len = 30;
  int* arr = NULL;

  testArray(&arr, len);
  printArray(arr, len);

  testBubbleSort(arr, len);
  printArray(arr, len);

  testQuickSort(arr, len);
  printArray(arr, len);

  return 0;
}
