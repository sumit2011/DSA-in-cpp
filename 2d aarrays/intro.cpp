#include<iostream>
using namespace std;

// check element is present or not
bool ispresent(int arr[][4], int target, int row, int col){
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if(arr[row][col] == target);
            return 1;
        }
        
    }
    return 0;
}

// to print row wise sum
void printSum(int arr[][4], int row, int col){
    cout<<"printing row wise sum: "<<endl;
    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 4; col++)
        {
            sum = sum+ arr[row][col];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

// to print column wise sum
void printSum(int arr[][4], int row, int col){
    cout<<"printing row wise sum: "<<endl;
    for (int col = 0; col < 3; col++)
    {
        int sum = 0;
        for (int row = 0; row < 4; row++)
        {
            sum = sum+ arr[row][col];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}


int main(){

    // create 2d arrays
    int arr[3][4];

    // taking input row wise
    cout<<"enter the elements: "<<endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cin>>arr[row][col];
        }
        
    }

    // taking input column wise
    // for (int col = 0; col < 3; col++)
    // {
    //     for (int row = 0; row < 4; row++)
    //     {
    //         cin>>arr[row][col];
    //     }
        
    // }

    //print
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
        
    }

    // int arr[3][4] = {1,2,3,4,5,6,7,8,9,1,2,3};
    // int arr[3][4] = {{1,11,111,1111},{2,22,222,2222}, {3,33,333,3333}};

    cout<<"enter the element to search: "<<endl;
    int target;
    cin>>target;

    if (ispresent(arr,target,3,4))
    {
        cout<<"found"<<endl;
    }
    else
    cout<<"not found"<<endl;
    
    printSum(arr,3,4);
    return 0;

    printColSum(arr,3,4);
}