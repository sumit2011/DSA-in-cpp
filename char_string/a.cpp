#include<iostream>
using namespace std;

// length of string
int getlength(char name[]){
    int count = 0;
    for(int i=0; name[i] != 0; i++){
        count ++;
    }
    return count;

}

// reverse the string 
void reverse(char name[],int n){
    int s=0;
    int e=n-1;
    while(s<e){
        swap(name[s++],name[e--]);
    }

}

// check palindrome case sensitive
bool checkpalindrome(char a[], int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        if(a[s] != a[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

// check palindrome not case sensitive
bool checkpalindrome(char a[], int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        if(tolowercase( a[s] ) !=  tolowercase( a[e]) ){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

// upper to lower case
char tolowercase(char ch){
    if(ch>='a' && ch <='z')
        return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

int main(){
    char name[20];

    cout << "enter your name " << endl;  // input-> sumit kumar
    cin>>name;

    cout<<"your name is: ";
    cout<< name <<endl;                 // output-> sumit

    name[2]= '\0';
    cout<<name<<endl;                   // output-> su

//length of string
    // name[20] = {"sumit"};
    cout<<"length: "<<getlength(name)<<endl;

//reverse a string
    int len = getlength(name);
    reverse(name,len);
    cout<<"name in reverse: "<<name<<endl;

// palindrome or not
    cout<<"palindrome or not: "<<checkpalindrome(name,len)<<endl;

// change to lowercase
    cout<<"character in lower case: " << tolowercase('A') << endl;


    return 0;


}