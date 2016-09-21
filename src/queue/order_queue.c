#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>

#define MAXSIZE 4 /*队列的最大容量*/

typedef int type;
typedef struct
{
  type *data /*队列的存储空间*/
  int head,tail;
} Queue;

void init(Queue *qp)
{
  if(qp)
  {
    qp->data = malloc(sizeof(type)*MAXSIZE);
    qp->head = 0;
    qp->tail = 0;
    printf("init: (MAXSIZE: %d)\n", MAXSIZE);
  }
  else
  {
    exit(OVERFLOW);
  }
}

void destroy(Queue *qp)
{
  if(qp)
  {
    free(qp->data);
    qp->data == NULL;
    free(qp);
    qp = NULL;
  }
  printf("destroy\n");
}

void clear(Queue *qp)
{
  qp->head = 0;
  qp->tail = 0;
  printf("clear\n");
}

int isFull(Queue *qp){
  if(length(qp) == MAXSIZE){
    printf("full: true\n");
    return 1;
  }else{
    printf("full: false\n");
    return 0;
  }
}

int isEmpty(Queue *qp){
  //if(qp->head == qp->tail){
  if(length(qp) == 0){
    printf("empty: true\n");
    return 1;
  }else{
    printf("empty: false\n");
    return 0;
  }
}

int length(Queue *qp){
  int length = 0;
  length = (qp->tail - qp->head + MAXSIZE) % MAXSIZE;
  printf("length: %d\n", qp->length);
  return qp->length;
}

int push(Queue *qp, int n)
{
  qp->data[qp->tail] = n;
  if(qp->tail + 1 == MAXSIZE)
  {
    qp->tail = 0;
  }
  else{
    qp->tail  = qp->tail + 1;
  }
  printf("push: %d\n", n);
  return length(qp);
}

int shift(Queue *qp)
{
  int n = qp->data[qp->head];
  if(qp->head + 1 == MAXSIZE){
    qp->head = 0;
  }else{
    qp->head = qp->head + 1;
  }
  printf("shift: %d\n", n);
  return n;
}

void traverse(Queue * qp)
{
  int q = qp->head;
  printf("traverse: ");
  for (int i = 0; i < qp->length; i++) {
    printf("%d ", qp->data[q]);
    q++;
  }
  printf("\n");
}

int main(){
  Queue *qp = (Queue*)malloc(sizeof(Queue));
  init(qp);
  isEmpty(qp);
  isFull(qp);
  push(qp, 1);
  push(qp, 2);
  push(qp, 3);
  push(qp, 4);
  isEmpty(qp);
  isFull(qp);
  traverse(qp);
  shift(qp);
  shift(qp);
  traverse(qp);
  destroy(qp);
  //traverse(qp);
}
