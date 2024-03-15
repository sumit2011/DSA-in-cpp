// valid palindrome leetcode
#include<iostream>
#include<string>


class solution
{
private:
    bool valid(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            return 1;
        else
            return 0;
    }

    // to lower case
    char tolowercase(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            return ch;
        else
        {
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    // check palindrome not case sensitive
    bool checkpalindrome(string a)
    {
        int s = 0;
        int e = a.length()-1;
        while (s <= e)
        {
            if (a[s] != a[e])
            {
                return 0;
            }
            else
            {
                s++;
                e--;
            }
        }
        return 1;
    }

public:
    bool ispalindrome(string s)
    {
        string temp = "";
        // remove invalid characters
        for (int j = 0; j < s.length(); j++)
        {
            if (valid(s[j]))
            {
                temp.push_back(s[j]);
            }
        }
        // lowercase conversion
        for (int j = 0; j < temp.length(); j++)
        {
            temp[j] = tolowercase(temp[j]);
        }
        //check palindrome
        return checkpalindrome(temp);
    }

};