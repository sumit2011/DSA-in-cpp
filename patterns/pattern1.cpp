#include<iostream>
using namespace std;

//star pattern if row == column
    // *****
    // *****
    // *****
    // *****
    // *****

int main(){

    int n;
    int i=0;
    cin>>n;

    while(i<n){
        int j=0;
        while(j<n){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
        
    }
    return 0;
}