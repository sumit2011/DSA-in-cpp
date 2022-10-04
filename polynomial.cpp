#include<iostream>
using namespace std;
int main(){

    int n;
    cout<<"enter the max no of terms in polynomial=";
    cin>>n;
    int a[n],b[n],c[n];
    for (int  i = n; i>=0; i--)
    {
        cout<<"enter the coeff of x^"<<i<<" of 1st polynomial=";
        cin>>a[i];
        cout<<"enter the coeff of x^"<<i<<" of 2nd polynomial=";
        cin>>b[i];
        c[i]=a[i]+b[i];
    }
    cout<<"polynomial ="; 
    for (int i = n; i >=0; i--)
    {
        cout<<c[i]<<"x^"<<i<<"+";
    }
    
    return 0;
}