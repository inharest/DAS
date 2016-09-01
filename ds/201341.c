#include <stdio.h>
#include <stdlib.h>

typedef struct _Element
{
  int element;
  struct _Element *next;
} Element;

typedef struct _Elements
{
  int element1, element2;
  struct _Elements *next;
} Elements;

Element* create(int* np, int len)
{
  Element* C = NULL;
  Element* c = NULL;
  int i = 0;
  while (i < len) {
    printf("%d ", *(np + i));
    Element *ep = malloc(sizeof(Element));
    ep->element = *(np + i);
    ep->next = NULL;
    if(C != NULL && c != NULL)
    {
      c->next = ep;
      c = ep;
    }
    else
    {
      C = ep;
      c = ep;
    }
    i++;
  }
  printf("\n");
  return C;
}

Elements* Descartes(Element *A, Element *B)
{
  Elements* C = NULL;
  Elements* c = NULL;
  Element* a = A;
  while (a != NULL)
  {
    Element* b = B;
    while(b != NULL)
    {
      Elements* esp = malloc(sizeof(Elements));
      esp->element1 = a->element;
      esp->element2 = b->element;
      esp->next = NULL;
      if(C != NULL && c != NULL)
      {
        c->next = esp;
        c = esp;
      }
      else
      {
        C = esp;
        c = esp;
      }
      b = b->next;
    }
    a = a->next;
  }
  return C;
}

int Number(Elements *C)
{
  int n = 0;
  Elements* c = C;
  while (c != NULL) {
    n++;
    c = c->next;
  }
  return n;
}

void traversal(Elements* C)
{
  Elements* c = C;
  printf("traversal: ");
  while (c != NULL) {
    printf("%d,%d  ", c->element1, c->element2);
    c = c->next;
  }
  printf("\n");
}

int main()
{
  // Element *A,*B;
  // Elements *C = Descartes(A,B);
  // int NC = Number(C);
  Element *A,*B;
  const int len = 3;
  int nap[3] = {1,2,3};
  int nbp[3] = {4,5,6};
  A = create(nap, len);
  B = create(nbp, len);
  Elements *C = Descartes(A,B);
  traversal(C);
  int NC = Number(C);
  printf("%d\n", NC);
  return 0;
}
