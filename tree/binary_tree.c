#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

// typedef struct TreeNode
// {
//   int data;
//   struct TreeNode* lchild;
//   struct TreeNode* rchild;
// }TreeNode;

void initTree(TreeNode** tnpp)
{
  *tnpp = NULL;
  printf("tree: init\n");
}

void destroy()
{

}

TreeNode* createTreeNode(int t)
{
  TreeNode* tnp = malloc(sizeof(TreeNode));
  tnp->data = t;
  tnp->lchild = NULL;
  tnp->rchild = NULL;
  return tnp;
}

void traversalTreeNodeStack(StackNode* snp)
{
  printf("stack: ");
  while(snp != NULL)
  {
    printf("%c ", snp->data->data);
    snp = snp->next;
  }
  printf("\n");
}

void createTree(TreeNode** tnpp, char* cp)
{
   StackNode* snp = NULL;
   char* str = cp;
   int lrflag = 0;
   while (*cp) {
     char c = *cp++;
     if(c == '@')
     {
       if(lrflag)
       {
          TreeNode* toptnp = NULL;
          do
          {
            popStack(&snp);
            toptnp = topStack(snp);
          } while(toptnp && toptnp->rchild);
       }
       lrflag = 1;
     }
     else
     {
       TreeNode* newtnp = createTreeNode((int)c);
       if(!isEmptyStack(snp))
       {
         TreeNode* toptnp = topStack(snp);
         if(!lrflag)
         {
           toptnp->lchild = newtnp;
         }
         else
         {
           toptnp->rchild = newtnp;
         }
       }
       else
       {
         *tnpp = newtnp;
       }
       pushStack(&snp, newtnp);
       lrflag = 0;
     }
     //traversalTreeNodeStack(snp);
   }
   destroyStack(&snp);
   printf("tree: create: %s\n", str);
}


void preorder(TreeNode* tnp)
{
  printf("tree: preorder: ");
  StackNode* snp = NULL;
  TreeNode* p = tnp;
  while(p != NULL || !isEmptyStack(snp))
  {
    while(p != NULL)
    {
      printf("%c", p->data);
      pushStack(&snp, p);
      p = p->lchild;
    }
    if(!isEmptyStack(snp))
    {
      p = popStack(&snp);
      p = p->rchild;
    }
  }
  destroyStack(&snp);
  printf("\n");
}

void inorder(TreeNode* tnp)
{
  printf("tree: inorder: ");
  StackNode* snp = NULL;
  TreeNode* p = tnp;
  while(p != NULL || !isEmptyStack(snp))
  {
    while(p != NULL)
    {
      pushStack(&snp, p);
      p = p->lchild;
    }
    if(!isEmptyStack(snp))
    {
      p = popStack(&snp);
      printf("%c", p->data);
      p = p->rchild;
    }
  }
  destroyStack(&snp);
  printf("\n");
}

void lastorder(TreeNode* tnp)
{
  printf("tree: lastorder: ");
  StackNode* snp = NULL;
  TreeNode* toptnp = NULL;
  TreeNode* pretnp = NULL;
  pushStack(&snp, tnp);
  while(!isEmptyStack(snp))
  {
    toptnp = topStack(snp);
    if((toptnp->lchild==NULL && toptnp->rchild==NULL)
      ||(pretnp!=NULL && (pretnp == toptnp->lchild || pretnp == toptnp->rchild)))
    {
      printf("%c", toptnp->data);
      popStack(&snp);
      pretnp = toptnp;
    }
    else
    {
      if(toptnp->rchild!=NULL)
      {
        pushStack(&snp, toptnp->rchild);
      }
      if(toptnp->lchild!=NULL)
      {
        pushStack(&snp, toptnp->lchild);
      }
    }
  }
  destroyStack(&snp);
  printf("\n");
}

void logtn(TreeNode* tnp)
{
  printf("%c\n", tnp->data);
}

int main()
{
  TreeNode* tnp = NULL;
  char* cp = "ABC@@DE@G@@F@@@";
  createTree(&tnp, cp);
  preorder(tnp);
  inorder(tnp);
  lastorder(tnp);
  return 0;
}
