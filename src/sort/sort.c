#include <stdio.h>
#include "util.h"

void bubbleSort(int arr[], int len)
{
  for (int i = 0; i < len; i++)
   {
    for (int j = 0; j < len - i - 1; j++)
    {
      if(arr[j] > arr[j+1])
      {
         //swap(&arr[j], &arr[j+1]);
         swapArray(arr,i,j);
      }
    }
  }
}

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
    //swap(&arr[i],&arr[j]);
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

// void shellSort(int arr[], int len) {
// 	int gap, i, j;
// 	int temp;
// 	for (gap = len >> 1; gap > 0; gap >>= 1)
// 		for (i = gap; i < len; i++) {
// 			temp = arr[i];
// 			for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
// 				arr[j + gap] = arr[j];
// 			arr[j + gap] = temp;
// 		}
// }

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

void testSwap(int len)
{
  double start = 0, end = 0,duration = 0;
  printf("Swap:\n");
  start = clock();
  int as[2] = {1,2};
  for(int i=0;i<len;i++)
  {
    swapArray(as, 0, 1);
  }
  end = clock();
  duration = (double)(end - start)/ CLOCKS_PER_SEC * 1000;
  printf("time: %f ms, %f s\n", duration, duration/1000);
}

void testRandomArray(int** arrp, int len)
{
  int max = len;
  int min = 1;
  double start = 0, end = 0,duration = 0;
  printf("RandomArray:\n");
  start = clock();
  *arrp = getRandomArray(len, min, max);
  end = clock();
  duration = (double)(end - start)/ CLOCKS_PER_SEC * 1000;
  printf("time: %f ms, %f s\n", duration, duration/1000);
  //printArray(arr, len);
}

void testRandomUniqueArray(int** arrp, int len)
{
  int max = len;
  int min = 1;
  double start = 0, end = 0,duration = 0;
  printf("RandomUniqueArray:\n");
  start = clock();
  *arrp = getRandomUniqueArray(len, min, max);
  end = clock();
  duration = (double)(end - start)/ CLOCKS_PER_SEC * 1000;
  printf("time: %f ms, %f s\n", duration, duration/1000);
  //printArray(arr, len);
}

void testArray(int** arrp, int len)
{
  if(len > 100)
  {
    testRandomArray(arrp, len);
  }
  else
  {
    testRandomUniqueArray(arrp, len);
  }
}

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

  // testBubbleSort(arr, len);
  // testQuickSort(arr, len);
  // testSelectionSort(arr, len);
  // testInsertionSort(arr, len);

  testMergeSort(arr, len);

  printArray(arr, len);
}
