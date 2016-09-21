#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

typedef struct
{
  Node* head;
  Node* tail;
} Queue;

void init(Queue* qp)
{
  qp->head = qp->tail = malloc(sizeof(Node));
  if(qp->head != NULL)
  {
    qp->head->next = NULL;
    printf("init\n");
  }
  else
  {
    exit(0);
    printf("init: error\n");
  }
}

void destroy(Queue* qp) {
  if(qp != NULL)
  {
    while(qp->head != NULL)
    {
      qp->tail = qp->head->next;
      free(qp->head);
      qp->head = qp->tail;
    }
    free(qp);
    qp = NULL;
  }
  printf("destroy\n");
}

int getLength(Queue* qp)
{
  int len = 0;
  return len;
}

int isEmpty(Queue* qp)
{
  // qp->head->next != NULL ?
  return qp->tail == qp->head;
}

void push(Queue* qp, int t)
{
  // create new node
  Node* np = malloc(sizeof(Node));
  if(NULL == np)
  {
    exit(0);
  }
  np->data = t;
  np->next = NULL;
  // set the last node point to new node
  qp->tail->next = np;
  // update *tail point
  qp->tail = np;
  printf("push: %d\n", t);
}

int shift(Queue* qp)
{
  int t = 0;
  Node* np = qp->head->next;
  if(isEmpty(sp))
  {
    t = np->data;
    qp->head->next = np->next;
    // update *tail point
    if(qp->tail == np)
    {
      qp->tail = qp->head;
    }
    free(np);
    np = NULL;
    printf("shift: %d\n", t);
  }
  else
  {
    printf("shift: empty\n");
  }
  return t;
}

void traversal(Queue *qp)
{
  printf("traversal: \n");
  Node* np = qp->head->next;
  while (np != NULL)
  {
    printf("%d ", np->data);
    np = np->next;
  }
  printf("\n");
}

int main()
{
  Queue* qp = malloc(sizeof(Queue));
  init(qp);
  push(qp, 1);
  traversal(qp);
  shift(qp);
  shift(qp);
  traversal(qp);
  push(qp, 2);
  push(qp, 3);
  push(qp, 4);
  traversal(qp);
  shift(qp);
  traversal(qp);
  return 0;
}
