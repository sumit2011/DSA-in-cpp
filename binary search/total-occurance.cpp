// pair <int, int> p;
//     p.first = 5;
//     p.second = 6;


#include<iostream>
using namespace std;


int firstOccurance(int arr[], int n, int key){
    int start = 0;
    int end = n-1;
    int mid = start +(end-start)/2;
    int ans = -1;
    while(start <= end)
    {
        if (arr[mid]== key)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {   // go to right part
            start = mid + 1;
        }
        else if (arr[mid] > key)
        {   // go to left part
            end = mid -1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int lastOccurance(int arr[], int n, int key){
    int start = 0;
    int end = n-1;
    int mid = start +(end-start)/2;
    int ans = -1;
    while(start <= end)
    {
        if (arr[mid]== key)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] < key)
        {   // go to right part
            start = mid + 1;
        }
        else if (arr[mid] > key)
        {   // go to left part
            end = mid -1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

pair<int , int> firstAndLastOccurance(int arr[], int n, int key){
    pair<int , int > p;
    p.first = firstOccurance(arr , n, key);
    p.second = lastOccurance(arr , n , key);
    return p;

}

int main() {
    int arr[9]={1,2,3,3,3,3,3,4,5};
    cout << " first occurace of 3 is index " << firstOccurance(arr, 9 , 3) << endl;
    cout << " last occurace of 3 is index " << lastOccurance(arr, 9 , 3) << endl;
    int a = firstOccurance(arr, 9 , 3);
    int b = lastOccurance(arr, 9 , 3);
    cout << " no of occurance of 3 is " << b-a + 1;
    firstAndLastOccurance(arr, 9, 3);

}