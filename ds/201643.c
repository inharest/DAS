#include <stdio.h>
#include <stdlib.h>

struct PNode
{
  int Coef; //coefficient 系数
  int Expn; //exponent 指数
  PNode *next;
};

void create(PNode* &P,int Coef[],int Expn[], int n)
{
  //printf("create: ");
  PNode* tail = NULL;
  for (int i = 0; i < n; i++) {
    PNode* p = (PNode*)malloc(sizeof(PNode));
    p->Coef = Coef[i];
    p->Expn = Expn[i];
    p->next = NULL;
    if(tail != NULL)
    {
      tail->next = p;
      tail = tail->next;
    }
    else
    {
      P = tail = p;
      //P = p; tail = p;
    }
    //printf("%dx^%d ", p->Coef, p->Expn);
  }
  //printf("\n");
}

void Derivative(PNode* &P)
{
  PNode* p = P;
  PNode* prep = P;
  while (p != NULL) {
    if(p->Expn != 0)
    {
      p->Coef = p->Coef * p->Expn;
      p->Expn = p->Expn - 1;
      prep = p;
      p = p->next;
    }
    else
    {
      if(prep != P)
      {
        prep->next = p->next;
      }
      else
      {
        P = p->next;
      }
      free(p);
      p = NULL;
    }
  }
}


void traversal(PNode* P)
{
  PNode* p = P;
  printf("traversal: ");
  while (p != NULL) {
    printf("%dx^%d ", p->Coef, p->Expn);
    p = p->next;
  }
  printf("\n");
}

int main()
{
  // const int n = 4;
  // int Coef[n] = {5, -3, 2, 12};
  // int Expn[n] = {3, 2, 1, 0};

  // const int n = 1;
  // int Coef[n] = {20};
  // int Expn[n] = {0};

  // const int n = 1;
  // int Coef[n] = {20};
  // int Expn[n] = {1};

  const int n = 4;
  int Coef[n] = {5, -3, 2, 12};
  int Expn[n] = {3, 2, 0, -1};

  PNode* P = NULL;
  
  create(P, Coef, Expn, n);

  traversal(P);

  Derivative(P);

  traversal(P);

  return 0;
}
