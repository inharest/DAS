#include <stdio.h>
#include <stdlib.h>

int biSearch(int Key, int n, int Data[]) {
  int index = -1;
  int low = 0,high = n - 1,mid = 0;
  while (low<=high) {
    mid = (low + high)/2;
    // printf("%d %d %d\n", low, mid, high);
    if(Key < Data[mid])
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  if(Data[mid] == Key)
  {
    index = mid;
  }
  return index;
}

int biSearch2(int Key, int n, int Data[]) {
  int index = -1;
  int low = 0,high = n - 1,mid = 0;
  while (low<=high) {
    mid = (low + high)/2;
    // printf("%d %d %d\n", low, mid, high);
    if(Key < Data[mid])
    {
      high = mid - 1;
    }
    else if(Key > Data[mid])
    {
      low = mid + 1;
    }
    else
    {
      index = mid;
      break;
    }
  }
  return index;
}

int main()
{
  const int n = 10;
  int arr[n];
  int i = 0;
  while (i<n) {
    arr[i] = i;
    printf("%d ", arr[i]);
    i++;
  }
  printf("\n");
  int key = 3;
  int index = -1;
  index = biSearch(key, n, arr);
  printf("%d\n", index);
  index = biSearch2(key, n, arr);
  printf("%d\n", index);
  return 0;
}
