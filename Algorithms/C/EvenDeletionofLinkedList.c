#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};
struct node *head = NULL;
int  counter = 0;

struct node *makenode(int makedata);
void deleteeven(struct node *first);
void shownodes(struct node *first);

int main(){
  int dataf, str = 1;

  if(head == NULL){
    printf("\nSince the list is empty, enter the list:");
    printf("\nEnter data for node: ");
    scanf("%d", &dataf);
    head = (struct node *)malloc(sizeof(struct node));
    head -> data = dataf;
    counter++;
    head -> next = NULL;
  }
  printf("\n Lets enter more nodes :- ");

  while(str == 1){
    counter++;
    struct node *temp, *q;
    q = head;

    printf("\nEnter data for node %d: ", counter);
    scanf("%d",&dataf);

    while(q->next != NULL){
      q = q->next;
    }

    temp = makenode(dataf);

    if(counter == 2){
      head -> next = temp;
    }

    if(counter > 2){
      q -> next = temp;
    }

    printf("\nWant to continue adding nodes: 1- yes, 0- no\n");
    scanf("%d", &str);
  }

  deleteeven(head);
  shownodes(head);

  return 0;
}

struct node *makenode(int makedata){
  struct node *ptr;
  ptr = (struct node *)malloc(sizeof(struct node));

  if(ptr == NULL){
    printf("\nMemory not available.");
    exit(1);
  }

  ptr -> data = makedata;
  ptr -> next = NULL;
  return ptr;
}

void deleteeven(struct node *first){
  struct node *q, *p, *temp;
  q = first;
  p = first;

  for(int i = 1; i < counter; i++){
    p = p-> next;
    if(i % 2 != 0){
      q->next = p->next;
      q = p;
      temp = p;
      continue;
    }
    q = q->next;
    free(temp);
    temp = NULL;
  }

}

void shownodes(struct node *first){
  struct node *q;
  q = first;
  printf("\n");

  while(q != NULL){
    if(q -> next == NULL){
      printf("%d\n",q -> data);
      break;
    }
    printf("%d -> ", q -> data);
    q = q -> next;
  }
}
