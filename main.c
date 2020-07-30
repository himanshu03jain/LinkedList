#include <stdio.h>
#include <stdlib.h>

struct node
{
   int data;
   struct node* next;
}*first = NULL;
void display(struct node* p)
{
    while(p!=NULL)
    {
        printf("%d -> ",p->data);
        p = p->next;
    }
}
void create(int a[],int n)
{
    struct node* t,*last;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;
    for(int i=1;i<n;i++)
    {
       t = (struct node*)malloc(sizeof(struct node));
       t->data = a[i];
       t->next = NULL;
       last->next = t;
       last = t;
    }

}
int count(struct node *p)
{
    int l=0;
    while(p)
    {
       l++;
       p=p->next;
    }
    return l;

}
int search (struct node*p,int key)
{
    if(key<0 && key>count(p))
        return -1;
    else{
        while(p)
        {
            if(key==p->data)
                return p->data;
            else
                p=p->next;
        }
    }

}
void insert(struct node *p,int pos,int x)
{
    struct node* t;
    int i;
    if(pos<0 || pos>count(p))
        return ;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    if(pos==0)
   {
       t->next=first;
       first = t;
   }
   else{
    for(i=0;i<pos-1;i++)
        p=p->next;
    t->next= p->next;
    p->next=t;

   }
}
int ldelete(struct node *p, int pos)
{
    int i;
    struct node *t = NULL;
    int x=-1;
    if(pos<1 || pos>count(p))
        return -1;
    if(pos==1)
    {
      t = first;
      x = first->data;
     first = first->next;
      free(t);
      return x;
    }
    else
    {
        for(i=0;i<pos-1;i++)
        {
            t = p;
            p = p->next;
        }
        t->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}
void reverse(struct node *p)
{
    struct node *q =  NULL;
    struct node *r = NULL;
    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
int main()
{
    int a[] = {3,4,7,8,9};
    create(a,5);
    //display(first);
    //insert(first,0,2);
    //insert(first,4,18);
    display(first);
    printf("\n\n");
   // printf("%d",search(first,8));
    //printf("\nlength of linked list is %d",count(first));
    // printf("%d",ldelete(first,5));
    //printf("\nfind key %d",search(first,1));
    reverse(first);
    display(first);
}
