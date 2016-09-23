#include <stdio.h>
#include "util.h"
#include "test.h"

// simple insert sort
void insertionSort(int arr[], int len)
{
  for (int i = 0; i < len; i++)
  {
    for (int j = i; j > 0; j--)
     {
      if(arr[j-1] > arr[j])
      {
        swapArray(arr,j-1,j);
      }
      else
      {
        break;
      }
    }
  }
}

void insertionSort2(int arr[], int len)
{
  for (int i = 1; i < len; i++)
   {
    int tmp = arr[i];
    int k = 0;
    for (int j = i; j > 0; j--)
     {
      if(arr[j-1] > tmp)
      {
        arr[j] = arr[j-1];
        //k = j - 1;
      }
      else
      {
        k = j;
        break;
      }
    }
    arr[k] = tmp;
    printArray(arr, len);
  }
}

void insertionSort3(int arr[], int len)
{
  for (int i = 1; i < len; i++)
   {
    int tmp = arr[i];
    int j = i;
    for (; j > 0; j--)
     {
      if(arr[j-1] > tmp)
      {
        arr[j] = arr[j-1];
      }
      else
      {
        break;
      }
    }
    arr[j] = tmp;
    printArray(arr, len);
  }
}

// insert half sort
void insertHalfSort(int arr[], int len)
{
  for (int i = 1; i < len; i++)
   {
    int tmp = arr[i];
    int k = 0;
    int low = 0, high = i - 1, mid = 0;
    if(arr[i-1] < arr[i])
    {
      k = i;
    }
    else
    {
      while (low<=high) {
        mid = (int)((low + high)/2);

        if(tmp < arr[mid])
        {
          high = mid - 1;
        }
        else
        {
          low = mid + 1;
        }
      }
      for (int j = i; j > low; j--)
      {
        arr[j] = arr[j-1];
      }
      k = low;
    }
    arr[k] = tmp;
    printArray(arr, len);
  }
}

// shell sort
void shellSort(int arr[], int len) {
	int gap, i, j;
	int tmp;
	for (gap = len >> 1; gap > 0; gap >>= 1)
		for (i = gap; i < len; i++) {
			tmp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > tmp; j -= gap)
				arr[j + gap] = arr[j];
			arr[j + gap] = tmp;
		}
}

// test
void testInsertionSort(int arr[], int len)
{
  double start = 0, end = 0,duration = 0;
  printf("insertionSort:\n");
  start = clock();
  insertionSort(arr, len);
  end = clock();
  duration = (double)(end - start)/ CLOCKS_PER_SEC * 1000;
  printf("time: %f ms, %f s\n", duration, duration/1000);
}

void testShellSort(int arr[], int len)
{
  double start = 0, end = 0,duration = 0;
  printf("shellSort:\n");
  start = clock();
  shellSort(arr, len);
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

  testInsertionSort(arr, len);
  printArray(arr, len);

  testShellSort(arr, len);
  printArray(arr, len);

  return 0;
}
