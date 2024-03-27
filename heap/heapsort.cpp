#include <bits/stdc++.h> 
// coding ninja
// min heap
void heapify(vector<int> &arr , int n ,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
    return;
}

vector<int> heapSort(vector<int>& arr, int n) {
	// Write your code here.
    // build heap
	for(int i=n/2; i>=0; i--){
		heapify(arr,n,i);
	}

    // sorting
	while(n--){
		swap(arr[n],arr[0]);
		heapify(arr,n,0);
        
	}
	return arr;
}