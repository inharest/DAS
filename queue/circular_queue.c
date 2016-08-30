#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

typedef struct
{
  int *data;
  int head;
  int tail;
} Queue;

int init(Queue* qp)
{
  qp->data = malloc(sizeof(Queue)*MAXSIZE);
  qp->head = 0;
  qp->tail = 0;
  printf("init: (MAXSIZE: %d)\n", MAXSIZE);
}

int destroy(Queue* qp)
{
  if(qp){
    free(qp);
    qp = NULL;
  }
  puts("destroy");
}

int isEmpty(Queue* qp)
{
  // printf("empty: %d\n", (qp->head == qp->tail));
  return qp->head == qp->tail;
}

int isFull(Queue* qp)
{
  // printf("full: %d\n", ((qp->tail + 1) % MAXSIZE == qp->head));
  return (qp->tail + 1) % MAXSIZE == qp->head;
}

int getLength(Queue* qp)
{
  //printf("length: %d\n", ((qp->tail - qp->head + MAXSIZE) % MAXSIZE));
  return (qp->tail - qp->head + MAXSIZE) % MAXSIZE;
}

int push(Queue* qp,int t)
{
  if(!isFull(qp))
  {
    qp->data[qp->tail] = t;
    qp->tail = (qp->tail + 1) % MAXSIZE;
    printf("push: %d\n", t);
  }
  else
  {
    printf("push: full\n");
  }
}

int shift(Queue* qp)
{
  int t = 0;
  if(!isEmpty(qp))
  {
    t = qp->data[qp->head];
    qp->head = (qp->head + 1) % MAXSIZE;
    printf("shift: %d\n", t);
  }
  else
  {
    printf("shift: empty\n");
  }
  return t;
}

void traversal(Queue* qp){
  int j = qp->head;
  int len = getLength(qp);
  printf("traversal:\n");
  printf("  queue: ");
  for(int i=0; i < len; i++)
  {
    printf("%d ", qp->data[j]);
    j = (j + 1)%MAXSIZE;
  }
  printf("\n");
  printf("  length: %d, head: %d, tail: %d\n", len, qp->head, qp->tail);
}

int main()
{
  Queue* qp = malloc(sizeof(Queue));
  init(qp);
  isEmpty(qp);
  isFull(qp);
  push(qp, 1);
  push(qp, 2);
  push(qp, 3);
  push(qp, 4);
  push(qp, 5);
  traversal(qp);
  shift(qp);
  shift(qp);
  shift(qp);
  shift(qp);
  shift(qp);
  traversal(qp);
  push(qp, 6);
  traversal(qp);
  shift(qp);
  traversal(qp);
  push(qp, 7);
  traversal(qp);
  shift(qp);
  traversal(qp);
  push(qp, 8);
  push(qp, 9);
  traversal(qp);
  shift(qp);
  shift(qp);
  traversal(qp);

  destroy(qp);
  return 0;
}
