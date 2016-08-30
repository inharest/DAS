#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int weight;
  int parent;
  int lchild;
  int rchild;
} Node, *HuffmanTree;

typedef char* HuffmanCode;

void initHuffmanTree(HuffmanTree* htp, int w[], int n)
{
  int m = 2 * n - 1;
  int i = 0;
  *htp = malloc((m + 1)*sizeof(Node));
  if(*htp != NULL)
  {
    for (i = 1; i <= n; i++) {
      (*htp)[i].weight = w[i];
      (*htp)[i].parent = 0;
      (*htp)[i].lchild = 0;
      (*htp)[i].rchild = 0;
    }
    for(i = n + 1; i <= m; i++)
    {
      (*htp)[i].weight = 0;
      (*htp)[i].parent = 0;
      (*htp)[i].lchild = 0;
      (*htp)[i].rchild = 0;
    }
    printf("huffman: init\n");
  }
  else
  {
    printf("huffman: init: error\n");
  }
}

void select(HuffmanTree* htp, int n, int* a,int* b)
{
  int i = 0;
  int min = 0;
  for (i = 1; i <= n; i++) {
    if((*htp)[i].parent == 0)
    {
      min = i;
      break;
    }
  }
  for (i = 1; i <= n; i++) {
    if((*htp)[i].parent == 0)
    {
      if((*htp)[i].weight < (*htp)[min].weight)
      {
        min = i;
      }
    }
  }
  *a = min;
  for (i = 1; i <= n; i++) {
    if((*htp)[i].parent == 0 && i != (*a))
    {
        min = i;
        break;
    }
  }
  for (i = 1; i <= n; i++) {
    if((*htp)[i].parent == 0 && i != (*a))
    {
      if((*htp)[i].weight < (*htp)[min].weight)
      {
        min = i;
      }
    }
  }
  *b = min;
}

void createHuffmanTree(HuffmanTree* htp, int n)
{
  int m = 2 * n - 1;
  int a = 0;
  int b = 0;
  for(int i = n + 1; i <= m; i++)
  {
    select(htp, i-1, &a, &b);
    //printf("%d %d\n",a , b );
    (*htp)[a].parent = i;
    (*htp)[b].parent = i;
    (*htp)[i].lchild = a;
    (*htp)[i].rchild = b;
    (*htp)[i].weight = (*htp)[a].weight + (*htp)[b].weight;
    printf("  %d (%d, %d)\n", (*htp)[i].weight, (*htp)[a].weight, (*htp)[b].weight);
  }
}

int main()
{
  HuffmanTree ht = NULL;
  int n = 4;
  int* w = malloc((n+1)*sizeof(int));

  printf("huffman: data: ");
  for (int i = 1; i <= n; i++) {
    w[i] = i;
    printf("%d ", w[i]);
  }
  printf("\n");


  initHuffmanTree(&ht, w, n);
  createHuffmanTree(&ht, n);
  return 0;
}
