#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10];
    int b[10];
    int t;

    //input of 1st array
    cout<<"enter the elements of a=";
    for (int i = 0; i < 10; i++)
    {
        cin>>a[i];
    }
    //sorting of first array
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(a[i]<a[j]){
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    //output of 1st sorted array
    cout<<"sorted a=";
    for (int i = 0; i < 10; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    //input of 2nd array
    cout<<"enter the element of b=";
    for (int  i = 0; i < 10; i++)
    {
        cin>>b[i];
    }

    //sorting of 2nd array
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(b[i]<b[j]){
                t=b[i];
                b[i]=b[j];
                b[j]=t;
            }
        }
    }
    //output of 2nd sorted array
    cout<<"sorted b=";
    for (int i = 0; i < 10; i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;

    //output of union elements
    cout<<"union of the array=";
    for (int i = 0; i < 10; i++)
    {
        if(a[i]==b[i])
        {
            cout<<a[i]<<" ";
        }

        if (a[i]!=b[i])
        {
            cout<<a[i]<<" "<<b[i]<<" ";
        }
    }
    return 0;
}
