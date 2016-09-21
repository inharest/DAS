#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

typedef struct
{
  int *data;
  int *top;
}Stack;

void init(Stack* sp)
{
  sp->data = malloc(sizeof(int)*MAXSIZE);
  if(sp->data != NULL)
  {
    sp->top = sp->data;
    printf("init: (MAXSIZE = %d)\n",MAXSIZE);
  }
  else
  {
    printf("init: error\n");
    exit(0);
  }
}

void destroy(Stack* sp)
{
  if(sp)
  {
    free(sp->data);
    sp->data = NULL;
    free(sp);
    sp = NULL;
  }
  printf("destroy\n");
}

void clear(Stack* sp)
{
  sp->top = sp->data;
}

int isFull(Stack* sp)
{
  return (sp->top - sp->data) == MAXSIZE;
}

int isEmpty(Stack* sp)
{
  return sp->top == sp->data;
}

int getLength(Stack* sp)
{
  return sp->top - sp->data;
}

int getTop(Stack* sp)
{
  int t = 0;
  if(!isEmpty(sp))
  {
    t = *(sp->top - 1);
    printf("getTop: %d\n", t);
  }
  else
  {
    printf("getTop: empty\n");
  }
  return t;
}

int push(Stack* sp,int t)
{
  if(!isFull(sp))
  {
    *sp->top++ = t; // *sp->top = t; sp->top++;
    printf("push: %d\n", t);
  }
  else
  {
    printf("push: %d full\n", t);
  }
  return getLength(sp);
}

int pop(Stack* sp)
{
  int t = 0;
  if(!isEmpty(sp))
  {
    t = *--sp->top; // (sp->top)--; t = *(sp->top);
    printf("pop: %d\n", t);
  }
  else
  {
    printf("pop: empty\n");
  }
  return t;
}

void traversal(Stack* sp)
{
  int len = getLength(sp);
  printf("traversal:\n");
  printf("  stack: ");
  for (int i = 0; i < len; i++) {
    printf("%d ", sp->data[i]);
  }
  printf("\n");
  printf("  length: %d\n", len);
}

int main()
{
  Stack* sp = malloc(sizeof(Stack));
  init(sp);
  getTop(sp);
  push(sp,1);
  push(sp,2);
  traversal(sp);
  getTop(sp);
  pop(sp);
  traversal(sp);
  getTop(sp);
  push(sp,3);
  push(sp,4);
  traversal(sp);
  getTop(sp);
  push(sp,5);
  push(sp,6);
  push(sp,7);
  push(sp,8);
  traversal(sp);
  getTop(sp);
  return 0;
}
