#include <stdio.h>
#include "util.h"
#include "test.h"

// merge sort
void mergeSort(int arr[], int reg[], int low, int high)
{
  if(low>=high) return;
  int mid = (int)((low + high)/2);
  int s1 = low, e1 = mid;
  int s2 = mid + 1, e2 = high;
  //mergeSort(arr, low, mid);
  //mergeSort(arr, mid+1, high);
  int k = low;
  mergeSort(arr, reg, s1, e1);
  mergeSort(arr, reg, s2, e2);

  while(s1 <= e1 && s2 <= e2)
  {
    reg[k++] = arr[s1] < arr[s2] ? arr[s1++] : arr[s2++];
  }
  while (s1 <= e1) {
    reg[k++] = arr[s1++];
  }
  while (s2 <= e2) {
    reg[k++] = arr[s2++];
  }
  for(k = low; k <= high; k++)
  {
    arr[k] = reg[k];
  }
}

//test
void testMergeSort(int arr[], const int len)
{
  double start = 0, end = 0,duration = 0;
  printf("mergeSort:\n");
  start = clock();
  int reg[len];
  mergeSort(arr, reg, 0, len - 1);
  end = clock();
  duration = (double)(end - start)/ CLOCKS_PER_SEC * 1000;
  printf("time: %f ms, %f s\n", duration, duration/1000);
}

int main()
{
  int len = 30;
  int* arr = NULL;
  // testSwap(len);

  testArray(&arr, len);
  printArray(arr, len);

  testMergeSort(arr, len);
  printArray(arr, len);

  return 0;
}
