#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head=NULL;
// node *tail=NULL;

void insertfirst(int d)
{
    node *ptr = new node();
    ptr->data=d;
    ptr->next=head;
    head=ptr;
}

void insertlast(int d)
{
    node *ptr = new node();
    ptr->data=d;
    ptr->next=NULL;
    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
        node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        


    }
}

void deletenode(int p)
{
    node *nextnode,*temp;
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
    node *temp=head;
    //temp=head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}

void sortlist()
{
    node *ptr , *cpt;
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


int main()
{
    // int t,size;
    // cout<<"size of linked list=";
    // cin>>size;
    // for (int i = 0; i < size; i++)
    // {
    //     cin>>t;
    //     insertlast(t);
    // }
    // sortlist();
    insertfirst(5);
    insertfirst(15);
    insertlast(10);
    insertlast(20);
    cout<<"beforesorting"<<endl;
    print();
    cout<<endl;
    cout<<"after sorting"<<endl;
    sortlist();
    print();
    cout<<endl;
    cout<<"after deletion"<<endl;
    deletenode(2);
    print();
}
