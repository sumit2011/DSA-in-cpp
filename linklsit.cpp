//singly linked list


#include<stdio.h>
#include<stdlib.h>

//creation of node
struct Node
{
    int data;
    struct Node *next;
} *head=NULL;

//insertion at begining
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

//insertation at end
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

//insertion at any position
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

//deletion at begining
void deletatBeg()
{
    struct Node *temp;
    temp=head;
    head=head->next;
    free(temp);
}

//deletion at end
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

//deletion at any position
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

//sorting of linked list
void sortlist()
{
    struct Node *ptr , *cpt;
    ptr = head;
    int temp;
    while(ptr->next != NULL)
    {
        cpt = ptr->next;
        while(cpt != NULL)
        {
            if(ptr->data > cpt->data)
            {
                temp=ptr->data;
                ptr->data = cpt->data;
                cpt->data = temp;
                
            }
            cpt=cpt->next;
        }
        ptr=ptr->next;
    }
}

//printing of linked list
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

//main function
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
    printf("\n");
    sortlist();
    print();
    return 0;
}
