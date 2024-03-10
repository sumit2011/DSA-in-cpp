#include<iostream>
using namespace std;

//pattern row == column
// 11111
// 22222
// 33333
// 44444
// 55555

// int main(){
//     int n;
//     cin>>n;
//     int i=1;

//     while(i<=n){
//         int j=0;
//         while(j<n){
//             cout<<i;
//             j++;
//         }
//         cout<<endl;
//         i++;
//     }
//     return 0;
// }

//12345
//12345
//12345
//12345
//12345

int main(){
    int n;
    cin>>n;
    int i=0;

    while(i<n){
        int j= 1;
        while(j<=n){
            // cout<<n-j+1;
            cout<<j;
            j++;
        }
        cout<<endl;
        i++;

    }
    return 0;
}