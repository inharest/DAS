#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *lchild,*rchild;
} bitree;

typedef struct QueueNode
{
  bitree* data;
  struct QueueNode* next;
} QueueNode;

typedef struct Queue
{
  QueueNode* head;
  QueueNode* tail;
} Queue;

void initQueue(Queue** qpp)
{
  Queue* qp = malloc(sizeof(Queue));
  QueueNode* qnp = malloc(sizeof(QueueNode));
  qnp->data = NULL;
  qnp->next = NULL;
  qp->head = qnp;
  qp->tail = qnp;
  *qpp = qp;
}

void pushQueue(Queue* qp, bitree* bt)
{
  QueueNode* qnp = malloc(sizeof(QueueNode));
  qnp->data = bt;
  qnp->next = NULL;
  qp->tail->next = qnp;
  qp->tail = qp->tail->next;
}

bitree* shiftQueue(Queue* qp)
{
  bitree* bt = NULL;
  if(qp->head->next != NULL)
  {
    QueueNode* qnp = qp->head->next;
    bt = qnp->data;
    qp->head->next = qnp->next;
    if(qp->tail == qnp)
    {
      qp->tail = qp->head;
    }
    free(qnp);
    qnp = NULL;
  }
  return bt;
}

int isEmptyQueue(Queue* qp)
{
  return qp->head->next == NULL;
}

void createTree(bitree** tnpp, char* cp, int* ip)
{
   bitree* tnp = malloc(sizeof(bitree));
   char c = *(cp + *ip);
   (*ip)++;
   printf("%c", c);
   if(c == '@')
   {
     tnp = NULL;
   }
   else
   {
     tnp = malloc(sizeof(bitree));
     if (!tnp)
     {
       exit(1);
     }
     tnp->data = c;
     createTree(&tnp->lchild, cp, ip);
     createTree(&tnp->rchild, cp, ip);
   }
   *tnpp = tnp;
}

void preorder(bitree* tnp)
{
  if(tnp != NULL)
  {
    printf("%c", tnp->data);
    preorder(tnp->lchild);
    preorder(tnp->rchild);
  }
}

void level_traverse(bitree* bt)
{
  Queue* qp = NULL;
  initQueue(&qp);

  if(bt != NULL)
  {
    pushQueue(qp, bt);
    while (!isEmptyQueue(qp))
    {
      bitree* p = shiftQueue(qp);
      if(p->lchild != NULL)
      {
        pushQueue(qp, p->lchild);
      }
      if(p->rchild != NULL)
      {
        pushQueue(qp, p->rchild);
      }
      printf("%c ", p->data);
    }
  }
}

int main()
{

  printf("bt: create: ");
  bitree* bt = NULL;
  char* cp = "ABC@@DE@G@@F@@@";
  int ci = 0;
  createTree(&bt, cp, &ci);
  printf("\n");
  printf("bt: preoreder: ");
  preorder(bt);
  printf("\n");

  level_traverse(bt);
  // Queue* qp = NULL;
  // initQueue(&qp);
  // pushQueue(qp, bt);
  // pushQueue(qp, bt->lchild);
  // bitree* tmpbt = shiftQueue(qp);
  // printf("%c\n", tmpbt->data);
  // tmpbt = shiftQueue(qp);
  // printf("%c\n", tmpbt->data);

  return 0;
}
