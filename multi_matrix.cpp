#include <iostream>

int main() {
    using namespace std;
    int a[2][2]={1,2,3,4};
    int b[2][2]={5,6,7,8};
    int c[2][2];
    // int sum =0;
    cout<<"matrix 1=\n";
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"matrix 2=\n";
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<2;i++)
    {
        int sum=0;
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                sum=sum+a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
        
    }
    cout<<"multipication of matrix=\n";
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}