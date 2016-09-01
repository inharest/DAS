#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;

typedef struct node
{
  datatype data;
  struct node *lchild, *rchild;
}bitree;

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

bool judgebitree(bitree* bt1, bitree* bt2)
{
  bool flag = false;
  if(bt1 != NULL && bt2 != NULL && bt1->data == bt2->data)
  {
    flag = true;
    flag = judgebitree(bt1->lchild, bt2->lchild);
    flag = judgebitree(bt1->rchild, bt2->rchild);
  }
  else if(bt1 == NULL && bt2 == NULL)
  {
    flag = true;
  }
  return flag;
}

int main()
{
  printf("bt1: create: ");
  bitree* bt1 = NULL;
  char* cp1 = "ABC@@DE@G@@F@@@";
  int ci1 = 0;
  createTree(&bt1, cp1, &ci1);
  printf("\n");
  printf("bt2: create: ");
  bitree* bt2 = NULL;
  char* cp2 = "ABC@@DE@G@@F@@@";
  int ci2 = 0;
  createTree(&bt2, cp2, &ci2);
  printf("\n");
  printf("bt1: preoreder: ");
  preorder(bt1);
  printf("\n");
  printf("bt2: preoreder: ");
  preorder(bt2);
  printf("\n");

  printf("tree: judgebitree: ");
  bool flag = judgebitree(bt1, bt2);
  // printf("%d", flag);
  if(flag){
    printf("true");
  }
  else
  {
    printf("false");
  }
  printf("\n");


  return 0;
}
