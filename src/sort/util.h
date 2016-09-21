#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inArray(int arr[], int len, int v){
  int flag = 0;
  for (int i=0; i<len; i++)
  {
    if(v == arr[i])
    {
      flag = 1;
      break;
    }
  }
  return flag;
}

int* getRandomArray(int len, int min, int max)
{
  int* arr = NULL;
  if(max - min + 1 >= len)
  {
    arr = malloc(len*sizeof(int));
    srand((unsigned)time(NULL));
    for (int i=0; i<len; i++)
    {
      arr[i] = rand() % max + min;
    }
  }
  else
  {
    printf("RandomArray: error\n");
  }
  return arr;
}

int* getRandomUniqueArray(int len, int min, int max)
{
  int* arr = NULL;
  if(max - min + 1 >= len)
  {
    arr = malloc(len*sizeof(int));
    srand((unsigned)time(NULL));
    for (int i=0; i<len; i++)
    {
      int v = rand()%max + min;
      int flag = inArray(arr,i,v);
      if(flag == 0)
      {
        arr[i] = v;
      }
      else
      {
        i--;
      }
    }
  }
  else
  {
    printf("RandomArray: error\n");
  }
  return arr;
}

void printArray(int arr[], int len)
{
  if(len > 100) return;
  printf("arr: ");
  for (int i=0; i<len; i++)
  {
      printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap(int* a, int* b)
{
  // way 1
  int tmp = 0;
  tmp = *a;
  *a = *b;
  *b = tmp;
  // way 2
  // *a = *a + *b;
  // *b = *a - *b;
  // *a = *a - *b;
  // way 3
  // *a = *a^*b;
  // *b = *a^*b;
  // *a = *a^*b;
}

void swapArray(int arr[], int i, int j)
{
  int tmp = 0;
  tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

#endif
