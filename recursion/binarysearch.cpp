#include<iostream>
using namespace std;

void print(int arr[] , int s , int e){
    for (int i = s; i <= e; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout << endl;
    
}
bool binarySearch(int *arr, int s, int e, int key){
    //base case
    print(arr, s ,e);
    if(s > e){
        return false;
    }

    int mid = (s+e)/2;

    if(arr[mid] == key){
        return true;
    }

    else if(arr[mid] > key){
        return binarySearch(arr , s , mid-1, key);
    }

    else{
        return binarySearch(arr , mid+1 , e , key);
    }
}

int main(){
    int arr[6] = {2,4,6,10,14,18};
    int size = 6;
    int key = 14;
    cout << binarySearch(arr , 0 , 5, key);
    return 0;
}