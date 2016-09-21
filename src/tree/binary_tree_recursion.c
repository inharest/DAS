#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
  int data;
  struct TreeNode* lchild;
  struct TreeNode* rchild;
}TreeNode;

void initTree(TreeNode** tnpp)
{
  *tnpp = NULL;
  printf("tree: init\n");
}

void destroy(TreeNode** tnpp)
{
  TreeNode* tnp = *tnpp;
  if(tnp != NULL)
  {
    destroy(&tnp->lchild);
    destroy(&tnp->rchild);
    free(tnp);
    tnp = NULL;
  }
}

void createTree(TreeNode** tnpp, char* cp, int* ip)
{
   TreeNode* tnp = malloc(sizeof(TreeNode));
   char c = *(cp + *ip);
   (*ip)++;
   printf("%c", c);
   if(c == '@')
   {
     tnp = NULL;
   }
   else
   {
     tnp = malloc(sizeof(TreeNode));
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

void preorder(TreeNode* tnp)
{
  if(tnp != NULL)
  {
    printf("%c", tnp->data);
    preorder(tnp->lchild);
    preorder(tnp->rchild);
  }
}

void inorder(TreeNode* tnp)
{
  if(tnp != NULL)
  {
    inorder(tnp->lchild);
    printf("%c", tnp->data);
    inorder(tnp->rchild);
  }
}

void lastorder(TreeNode* tnp)
{
  if(tnp != NULL)
  {
    lastorder(tnp->lchild);
    lastorder(tnp->rchild);
    printf("%c", tnp->data);
  }
}

TreeNode* presearch(TreeNode* tnp, int x)
{
  TreeNode* p = NULL;
  if(tnp != NULL)
  {
    if(tnp->data == x)
    {
      p = tnp;
    }
    else
    {
      p = presearch(tnp->lchild,x);
      if(!p)
      {
        p = presearch(tnp->rchild,x);
      }
    }
  }
  return p;
}

int countleaf(TreeNode* tnp)
{
  int n = 0;
  if(tnp!=NULL)
  {
    if((!tnp->lchild)&&(!tnp->rchild))
    {
      n++;
    }
    n += countleaf(tnp->lchild);
    n += countleaf(tnp->rchild);
  }
  return n;
}

int count(TreeNode* tnp)
{
  int n = 0;
  if(tnp != NULL)
  {
    n += count(tnp->lchild);
    n += count(tnp->rchild);
    n += 1;
  }
  return n;
}

int depth(TreeNode* tnp)
{
  int n = 0;
  if(tnp != NULL)
  {
    int l = depth(tnp->lchild);
    int r = depth(tnp->rchild);
    n = 1 + ( l > r ? l : r );
  }
  return n;
}

TreeNode* createTreeNode(int data, TreeNode* lp, TreeNode* rp)
{
  TreeNode* tnp = malloc(sizeof(TreeNode));
  tnp->data = data;
  tnp->lchild = lp;
  tnp->rchild = rp;
  return tnp;
}

TreeNode* copytree(TreeNode* tnp)
{
  TreeNode* newtnp = NULL;
  TreeNode* newlp = NULL;
  TreeNode* newrp = NULL;
  if(tnp != NULL)
  {
      newlp = copytree(tnp->lchild);
      newrp = copytree(tnp->rchild);
      // printf("copy\n");
      newtnp = createTreeNode(tnp->data, newlp, newrp);
  }
  return newtnp;
}


void logtn(TreeNode* tnp)
{
  printf("%c\n", tnp->data);
}

int main()
{
  TreeNode* tnp = NULL;
  char* cp = "ABC@@DE@G@@F@@@";
  int ci = 0;
  printf("tree: create: ");
  //createTree(&tnp);
  createTree(&tnp, cp, &ci);
  printf("\n");
  printf("tree: preoreder: ");
  preorder(tnp);
  printf("\n");
  printf("tree: inoreder: ");
  inorder(tnp);
  printf("\n");
  printf("tree: lastoreder: ");
  lastorder(tnp);
  printf("\n");
  printf("tree: presearch: ");
  TreeNode* p = presearch(tnp,(int)'D');
  if(p!=NULL)
  {
    printf("%c\n", p->data);
  }
  else
  {
    printf("none\n");
  }
  printf("tree: count: %d\n", count(tnp));
  printf("tree: countleaf: %d\n", countleaf(tnp));
  printf("tree: depth: %d\n", depth(tnp));
  printf("tree: copytree: ");
  TreeNode* newp = copytree(p);
  preorder(newp);
  printf("\n");

  printf("tree: destroy\n");
  return 0;
}
