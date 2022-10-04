#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // int x,y;
    // cout<<"how many elements do you want to enter in array a and b respectively=";
    // cin>>x>>y;

    int a[10];
    int b[10];
    int t;

    //input of 1st array
    cout << "enter the elemants of array a ";
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    //sorting of 1st array
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(a[i]<a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }

    //input of 2nd array
    cout << "enter the elements of array b ";
    for (int i = 0; i < 10; i++)
    {
        cin >> b[i];
    }
    //sorting of 2nd array
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(b[i]<b[j])
            {
                t=b[i];
                b[i]=b[j];
                b[j]=t;
            }
        }
    }

    //output of intersection elements
    cout<<endl<<"intersection elements";
    for (int i = 0; i < 10; i++)
    {
        if (a[i] == b[i])
        {
            cout << a[i] << endl;
        }
    }

    return 0;
}
