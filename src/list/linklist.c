#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode
{
  int data;
  struct LinkNode* next;
} LinkNode;

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
  LinkNode* lnp = NULL;
  while (*lnpp != NULL) {
    lnp = (*lnpp)->next;
    free(*lnpp);
    *lnpp = lnp;
  }
  printf("destroy: success\n");
}

void createByHead(LinkNode* lnp, char* cp)
{
  char* str = cp;
  while(*cp)
  {
    char c = *cp;
    LinkNode* p = malloc(sizeof(LinkNode));
    if(p != NULL)
    {
      p->data = (int)c;
      p->next = lnp->next;
      lnp->next = p;
    }
    else
    {
      printf("createByHead: malloc fail at %c\n", c);
      exit(0);
    }
    cp++;
  }
  printf("createByHead: %s\n", str);
}

void createByTail(LinkNode* lnp, char* cp)
{
  char* str = cp;
  LinkNode* tail = lnp;
  while(*cp)
  {
    char c = *cp;
    LinkNode* p = malloc(sizeof(LinkNode));
    if(p != NULL)
    {
      p->data = (int)c;
      p->next = NULL;
      tail->next = p;
      tail = tail->next; //tail = p;
    }
    else
    {
      printf("createByTail: malloc fail at %c\n", c);
      exit(0);
    }
    cp++;
  }
  printf("createByTail: %s\n", str);
}


// merge two ordered list to a new ordered list
LinkNode* mergeByTail(LinkNode* alnp, LinkNode* blnp)
{
  LinkNode* ap = alnp->next;
  LinkNode* bp = blnp->next;
  LinkNode* cp = alnp;
  LinkNode* clnp = alnp;

  while (ap != NULL && bp != NULL) {
    if(ap->data <= bp->data)
    {
      cp->next = ap;
      cp = cp->next;
      ap = ap->next;
    }
    else
    {
      cp->next = bp;
      cp = cp->next;
      bp = bp->next;
    }
  }

  if(ap != NULL)
  {
    cp->next = ap;
  }

  if(bp != NULL)
  {
    cp->next = bp;
  }

  free(blnp);
  blnp = NULL;

  return clnp;
}

LinkNode* reverse(LinkNode* lnp)
{
  LinkNode* tail = lnp->next;
  LinkNode* p = NULL;
  while (tail != NULL && tail->next != NULL) {
    p = tail->next;
    tail->next = p->next;
    p->next = lnp->next;
    lnp->next = p;
  }
  return lnp;
}

LinkNode* reverseWithHead(LinkNode* lnp)
{
  LinkNode* tail = lnp;
  LinkNode* p = NULL;
  while (lnp != NULL && lnp->next != NULL) {
    p = lnp->next;
    lnp->next = p->next;
    p->next = tail;
    tail = p;
  }
  return tail;
}

LinkNode* insert(LinkNode* lnp, int n, int value)
{
  LinkNode* tmplnp = NULL;
  LinkNode* p = lnp->next;
  int i = 0;
  while(p != NULL && i < n - 1)
  {
    p = p->next;
    i++;
  }
  if(p != NULL && i <= n) // test if p==lnp or i>n
  {
    tmplnp = malloc(sizeof(LinkNode));
    tmplnp->data = value;
    tmplnp->next = p->next;
    p->next = tmplnp;
    printf("insert: %c at %d\n", value, n);
  }
  else
  {
    printf("insert: error\n");
  }
  return tmplnp;
}

LinkNode* delete(LinkNode* lnp, int n)
{
  LinkNode* tmplnp = NULL;
  LinkNode* p = lnp->next;
  int i = 0;
  if(p!=NULL)
  {
    while (p!=NULL && i < n - 1) {
      p = p->next;
      i++;
    }
    if(p!=NULL && i <= n)
    {
      tmplnp = p->next;
      p->next = p->next->next;
      // didn't free tmplnp
      printf("delete: %c at %d\n", tmplnp->data, n);
    }
    else
    {
      printf("delete: error\n");
    }
  }
  else
  {
    printf("delete: empty\n");
  }
  return tmplnp;
}


LinkNode* getByIndex(LinkNode* lnp, int n)
{
  LinkNode* p = lnp->next;
  int i = 0;
  if(p != NULL)
  {
    while (p != NULL && i < n) {
      p = p->next;
      i++;
    }
    if(p != NULL && i < n + 1) // (p != NULL && i == n) or (!!(p!=NULL && i<n+1) => !(p==NULL || i>n))
    {
      printf("getByIndex: %c at %d\n", p->data, n);
    }
    else
    {
      printf("getByIndex: error\n");
    }
  }
  else
  {
    printf("getByIndex: empty\n");
  }
  return p;
}

LinkNode* getByValue(LinkNode* lnp, int v)
{
  LinkNode* p = lnp->next;
  int i = 0;
  if(p != NULL)
  {
    while (p != NULL && p->data != v) {
      p = p->next;
      i++;
    }
    if(p!=NULL){
      printf("getByValue: %c at %d\n", p->data, i);
    }
    else
    {
      printf("getByValue: error\n");
    }
  }
  else
  {
    printf("getByValue: empty\n");
  }
  return p;
}

int getLength(LinkNode* lnp)
{
  LinkNode* p = lnp->next;
  int i = 0;
  while (p!=NULL) {
    p = p->next;
    i++;
  }
  printf("getLength: %d\n", i);
  return i;
}

void traversal(LinkNode* lnp)
{
  LinkNode* p = lnp->next;
  int i = 0;
  printf("traversal: \n");
  printf("  list: ");
  while(p != NULL)
  {
    printf("%c ", p->data);
    p = p->next;
    i++;
  }
  printf("\n");
  printf("  length: %d\n", i);
}

void traversalWithHead(LinkNode* lnp)
{
  LinkNode* p = lnp;
  int i = 0;
  printf("traversal: \n");
  printf("  list: ");
  while(p != NULL)
  {
    printf("%c ", p->data);
    p = p->next;
    i++;
  }
  printf("\n");
  printf("  length: %d\n", i);
}


int main()
{
  char* str = "abcdef";
  LinkNode* lnp = NULL;
  init(&lnp);
  //createByHead(lnp, str);
  createByTail(lnp, str);
  traversal(lnp);
  getLength(lnp);
  insert(lnp, 0, (int)'g');
  insert(lnp, 7, (int)'h');
  insert(lnp, 3, (int)'i');
  traversal(lnp);
  getLength(lnp);
  delete(lnp, 3);
  delete(lnp, 7);
  delete(lnp, 0);
  delete(lnp, 8);
  traversal(lnp);
  getLength(lnp);
  for (int i = 0; i < 8; i++)
  {
    getByIndex(lnp, i);
  }
  for (int i = (int)"a"; i < 8; i++)
  {
    getByValue(lnp, i);
  }

  destroy(&lnp);

  LinkNode* alnp = NULL;
  init(&alnp);
  createByTail(alnp, "abdfkl");
  LinkNode* blnp = NULL;
  init(&blnp);
  createByTail(blnp, "ceghijmn");
  traversal(alnp);
  traversal(blnp);
  LinkNode* clnp = mergeByTail(alnp, blnp);

  traversal(clnp);
  reverse(clnp);
  traversal(clnp);
  LinkNode* dlnp = reverseWithHead(clnp);
  traversalWithHead(dlnp);

  return 0;
}
