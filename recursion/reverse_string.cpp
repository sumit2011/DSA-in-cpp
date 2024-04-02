#include<iostream>
using namespace std;

void reverse(string &str , int i, int j){
    //base case
    cout << str <<endl;
    if(i > j){
        return;
    }
    swap(str[i] , str[j]);
    i++;
    j--;

    reverse(str , i , j);
}

int main(){

    string str = "sumit";
    reverse(str , 0 , str.length()-1);
    cout << str <<endl;
    return 0;

}