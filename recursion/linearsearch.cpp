#include<iostream>
using namespace std;

void print(int arr[] , int n){
    cout<<"size of array is "<< n<< endl;

    for(int i =0; i<n ; i++){
        cout<<arr[i] <<" ";
    }
    cout<<endl;
}
bool linearsearch(int arr[] , int size, int k){
    print(arr,size);
    // base case
    if(size == 0){
        return false;
    }

    if(arr[0] == k){
        return true;
    }

    else{
        bool remainingpart = linearsearch(arr+1 , size-1, k);
        return remainingpart;

    }
}

int main(){
    int arr[5] = {3,5,1,2,6};
    int size = 5;
    int key = 6;
    bool ans = linearsearch(arr , size, key);
    if(ans){
        cout<<"present" <<endl;
    }
    else
        cout<<"absent"<<endl; 
    return 0;
}