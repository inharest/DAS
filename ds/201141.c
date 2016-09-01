#include <stdio.h>
#include <stdlib.h>

struct Set
{
  int element;
  struct Set* next;
};

Set* Intersection(Set* A, Set* B)
{
  Set* C = NULL;
  Set* c = NULL;
  Set* a = A;
  while (a != NULL)
  {
    Set* b = B;
    while (b != NULL)
    {
      if(a->element == b->element)
      {
        Set* p = (Set*)malloc(sizeof(Set));
        p->element = a->element;
        p->next = NULL;
        if(C != NULL && c != NULL)
        {
          c->next = p;
          c = p;
        }
        else
        {
          C = p;
          c = p;
        }
        break;
      }
      b = b->next;
    }
    a = a->next;
  }
  return C;
}

int Cardinatlity(Set* A)
{
  int n = 0;
  Set* p = A;
  while (p != NULL) {
    n++;
    p = p->next;
  }
  return n;
}

Set* create(int arr[], int len)
{
  Set* C = NULL;
  Set* c = NULL;
  for(int i=0; i < len; i++)
  {
    Set* p = (Set*)malloc(sizeof(Set));
    p->element = arr[i];
    p->next = NULL;
    if(C != NULL && c != NULL)
    {
      c->next = p;
      c = p;
    }
    else
    {
      C = p;
      c = p;
    }
  }
  return C;
}

void traverse(Set* C)
{
  Set* p = C;
  printf("traverse: ");
  while (p != NULL) {
    printf("%d ", p->element);
    p = p->next;
  }
  printf("\n");
}

int main()
{
  int as[4] = {2,3,4,5};
  int bs[3] = {1,3,5};
  Set* A = create(as, 4);
  Set* B = create(bs, 3);
  traverse(A);
  traverse(B);
  Set* C = Intersection(A, B);
  traverse(C);
  int NUMC =  Cardinatlity(C);
  printf("Cardinatlity: %d\n", NUMC);
  return 0;
}
