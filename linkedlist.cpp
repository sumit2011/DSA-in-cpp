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

void insertAtPos(int p ,int d)
{
    node *ptr = new node();
    ptr->data=d;
    ptr->next=NULL;
    node *temp=head;
    int i;
    while (i<p)
    {
        temp=temp->next;
        i++;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    
}

void deletenode(int d)
{
    node *ptr=new node();
    ptr->data=d;
    ptr->next=NULL;
    node *temp=head;
    while (temp->next != NULL)
    {
        if(temp->data==d)
        {
            
            break;
        }
        temp=temp->next;
    }
    temp->next=ptr->next;
    free(ptr);
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

int main()
{
    int t,size;
    cout<<"size of linked list=";
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cin>>t;
        insertlast(t);
    }
    insertAtPos(3 , 11);
    deletenode(20);
    // insertfirst(5);
    // insertfirst(15);
    // insertlast(10);
    // insertlast(20);
    // deletenode(15);
    print();
}