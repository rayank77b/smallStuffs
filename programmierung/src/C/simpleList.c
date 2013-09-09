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
    printf("Node: data: %d  self: %p next: %p\n", l->data, l, l->next);
}

// iterate the list and print it out
void printList(list_t *r) {
    list_t *p;
    for(p=r; p->next!=NULL; p=p->next) {
        printNode(p);
    }
    printNode(p);
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

}

int main() {
    list_t *root, *a;
    int i;
    
    root=NULL;
    
    for(i=0;i<50;i++) {
        a = new_node(i);
        add(&root, a);
    }
   
    printList(root);

return 0;
}
