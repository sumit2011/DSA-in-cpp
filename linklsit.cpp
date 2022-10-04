//
//***SINGLY LINKED LISTINSERTION AT BIG,END,DESIRED POS***//
//
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Node
{
    int data;
    struct Node *next;
} *head=NULL;


void insertAtBeg(int value)
{
    struct Node *newnode;                 
     newnode = (struct Node*)malloc(sizeof(struct Node));
     newnode->data=value;                    
     if (head==NULL)
     {
         newnode->next=NULL;
          head=newnode;
     }
     else{
        newnode->next=head;
        head=newnode;
     }
    printf("\n\n*Inserted successfully at beginning*\n");  
}


void insertATend(int value)
{
  struct Node *newnode;
  newnode=(struct Node*)malloc(sizeof(struct Node));
  newnode->data=value;
  if(head==NULL)
  {
    newnode->next=NULL;
    head = newnode;
  }
  else{
    struct Node *temp;
    temp=head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
  }
  printf("\n\n*Inserted Successfully in END *\n");
}


 void insertAtPos(int p,int value)
 {
struct Node *newnode,*temp=NULL;     
int pos,i=1;
    newnode= (struct Node*)malloc(sizeof(struct Node));
    pos=p;
    newnode->data=value;
    temp=head;
    while(i<pos-1)
    {
      temp = temp->next;
      i++;
    }
    newnode->next = temp->next;
    temp->next = newnode; 
 }


 void deletatBeg()
 {
  struct Node *temp;
  temp=head;
  head=head->next;
  free(temp);
 }


 void deletatEnd()
 {
     struct Node *temp,*prev;
     prev=temp=head;
     while(temp->next!=NULL)
     {
         prev=temp;
         temp=temp->next;
     }
         prev->next=NULL;
         free(temp);
 }

void deletatPos(int p)
{
struct Node *nextnode,*temp;
int pos,i=1;
pos=p;
nextnode=temp=head;
while(i<pos)
{
  temp=nextnode;
  nextnode=nextnode->next;
  i++;
}
temp->next=nextnode->next;
free(nextnode);
}


void print()
{
 struct Node *temp;
 temp=head;
 while(temp!=NULL)
 {
  printf("%d-->",temp->data);
  temp=temp->next;
 }
 printf("NULL");
}


int main()
{
insertAtBeg(34);
insertAtBeg(45);
insertAtBeg(72);
insertAtBeg(5);
insertAtBeg(89);
insertAtBeg(99);
insertATend(23);
insertATend(55);
insertATend(13);
insertATend(41);
insertAtPos(6,8992);
deletatBeg();
 deletatEnd();
 deletatPos(3);
print();

}
