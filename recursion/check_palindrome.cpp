#include<iostream>
using namespace std;

bool checkPalindrome(string &str , int s, int e){
    if(s > e){
        return true;
    }

    if(str[s] == str[e]){
        s++;
        e--;
        return checkPalindrome(str, s, e);
    }

    return false;
    
}

int main(){
    string str = "sumitimus";
    cout<<checkPalindrome(str , 0 , str.length() - 1);

    return 0;
}