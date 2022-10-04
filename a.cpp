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

// void deletenode(int d)
// {
//     node *ptr=new node();
//     ptr->data=d;
//     ptr->next=NULL;
//     node *temp=head;
//     while (temp->next != NULL)
//     {
//         if(temp->data==d)
//         {
//             free(temp);
//             return;
//         }
//         temp=temp->next;
//     }
// }


void print()
{
    node *temp=head;
    //temp=head;
    while (temp->next != NULL)
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
    
    // insertfirst(5);
    // insertfirst(15);
    // insertlast(10);
    // insertlast(20);
    // deletenode(15);
    print();
}