#ifndef TEST_H
#define TEST_H


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

#endif
