#include <stdio.h>
#include <stdlib.h>

// simple on direction linked list
typedef struct list_s{
    int data;
    struct list_s *next;  // pointer to the next node
}list_t;

// create new node and set the data
list_t *new_node(int d)
{
  list_t *p;
  if((p = malloc(sizeof *p)) != NULL)
  {
    p->data=d;
    p->next=NULL;
  }
  return p;
}

void printNode(list_t *l) {
    if(l!=NULL)
        printf("Node: data: %d  self: %p next: %p\n", l->data, l, l->next);
    else
        printf("Node is void NULL\n");
}

// get the count of the list
int getSize(list_t **r) {
    int cnt=0;
    list_t *p;
    for(p=*r; p!=NULL; p=p->next) {
        cnt++;
    }
    return cnt;
}

// iterate the list and print it out
void printList(list_t *r) {
    list_t *p;
    printf("---------------------------------------------------------------------\n");
    printf(" Size of the List: %d\n", getSize(&r));
    for(p=r; p!=NULL; p=p->next) {
        printNode(p);
    }
    printf("---------------------------------------------------------------------\n");
}

// add a list at the end of list. start from root list
void add(list_t **r, list_t *c) {
    list_t *p;
    if(*r==NULL) {  // no list in root 
        *r=c;
    } else {
        // gehe zu letztem element
        for(p=*r; p->next!=NULL; p=p->next) {
        }
        p->next=c;
    }
}


// delete a node from the list
void del(list_t **r, list_t *c) {
    list_t *p, *d;
    if(*r!=NULL) {
        for(p=*r; p->next!=c; p=p->next) {
            if(p==NULL) // reaching end
                return;
        }
        if(p->next->next==NULL) {
            p->next=NULL;
        } else {
            p->next=p->next->next;
        }
        free(c);
    }
}

list_t * getNode(list_t **r, int d) {
    list_t *p;
    for(p=*r; p!=NULL; p=p->next) {
        if(p->data==d)
            return p;
    }
    return NULL;
}

void delNode(list_t **r, int d) {
    list_t *b;
    b=getNode(r, d);
    if(b!=NULL)
        del(r, b);
}

int main() {
    list_t *root, *a, *b;
    int i;
    
    root=NULL;
    printList(root);
    for(i=0;i<10;i++) {
        a = new_node(i);
        add(&root, a);
        if(i==5)
            b=a;
    }
   
    printList(root);
    printNode(b);
    del(&root, b);
    printList(root);
    
    b=getNode(&root, 8);
    printNode(b);
    delNode(&root, 8);
    printList(root);
    
return 0;
}
