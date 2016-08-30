#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node* next;
}Node;

typedef struct
{
  Node* top;
}Stack;

void init(Stack* sp)
{
  Node* np = malloc(sizeof(Node));
  np->data = 0;
  np->next = NULL;
  sp->top = np;
  printf("init\n");
}

void destroy(Stack* sp)
{
  while (sp->top != NULL) {
    Node* np = sp->top->next;
    free(sp->top);
    sp->top = np;
  }
  printf("destroy\n");
}

int isEmpty(Stack* sp)
{
  return sp->top->next == NULL;
}

int getLength(Stack* sp)
{
  int len = 0;
  Node* np = sp->top;
  while(np->next != NULL)
  {
    len++;
    np = np->next;
  }
  return len;
}

int getTop(Stack* sp)
{
  int t = 0;
  if(!isEmpty(sp))
  {
    t = sp->top->data;
    printf("top: %d\n", t);
  }
  else
  {
    printf("top: empty\n");
  }
  return t;
}

int push(Stack* sp,int t) {
  Node* np = malloc(sizeof(Node));
  np->data = t;
  np->next = sp->top;
  sp->top = np;
  printf("push: %d\n", t);
  return 0;
}

int pop(Stack* sp)
{
  int t = 0;
  if(!isEmpty(sp))
  {
    Node* np = sp->top;
    t = np->data;
    sp->top = np->next;
    free(np);
    np = NULL;
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
  Node* np = sp->top;
  printf("traversal:\n");
  printf("  stack: ");
  while(np->next != NULL)
  {
    printf("%d ", np->data);
    np = np->next;
  }
  printf("\n");
  printf("  length: %d\n", getLength(sp));
}

int main()
{
  Stack* sp = malloc(sizeof(Stack));
  init(sp);
  pop(sp);
  getTop(sp);
  push(sp,1);
  push(sp,2);
  push(sp,3);
  push(sp,4);
  traversal(sp);
  getTop(sp);
  pop(sp);
  pop(sp);
  traversal(sp);
  getTop(sp);
  push(sp,5);
  push(sp,6);
  traversal(sp);
  getTop(sp);
  destroy(sp);
  return 0;
}
