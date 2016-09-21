#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode
{
  int data;
  struct LinkNode* next;
}LinkNode;

void init(LinkNode** lnpp)
{
  LinkNode* lnp = malloc(sizeof(LinkNode));
  if(lnp != NULL)
  {
    lnp->data = (int)'#';
    lnp->next = NULL;
    *lnpp = lnp;
    printf("init: success\n");
  }
  else
  {
    printf("init: malloc fail\n");
  }
}

void destroy(LinkNode** lnpp)
{
  if(*lnpp != NULL)
  {
    destroy(&((*lnpp)->next));
    free(*lnpp);
    *lnpp = NULL;
  }
}

void create(LinkNode** lnpp, char *cp)
{
  LinkNode* lnp = NULL;
  if(*cp == '\0')
  {
    lnp = NULL;
    *lnpp = lnp;
  }
  else
  {
    lnp = malloc(sizeof(LinkNode));
    if(lnp != NULL)
    {
      lnp->data = (int)(*cp);
      create(&(lnp->next), cp + 1);
      *lnpp = lnp;
    }
    else
    {
      exit(0);
    }
  }
}

LinkNode* reverse(LinkNode* lnp)
{
  LinkNode* tmplnp = NULL;
  if(lnp == NULL || lnp->next == NULL)
  {
    tmplnp = lnp;
  }
  else
  {
    tmplnp = reverse(lnp->next);
    lnp->next->next = lnp;
    lnp->next = NULL;
  }
  return tmplnp;
}

void traversal(LinkNode* lnp)
{
  if(lnp != NULL)
  {
    printf("%c ", lnp->data);
    traversal(lnp->next);
  }
}

int main()
{
  LinkNode* lnp = NULL;
  init(&lnp);
  char* str = "abcdef";
  create(&(lnp->next), str);
  traversal(lnp);
  printf("\n");
  traversal(lnp);
  printf("\n");
  LinkNode* tmplnp = reverse(lnp);
  traversal(lnp);
  printf("\n");
  traversal(tmplnp);
  printf("\n");
  destroy(&tmplnp);
  return 0;
}
