#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string x,res;
    char temp;
    cin >> x;
    for(int i=0;i<x.size();i++)
    {
        if(x[i]=='.')
        {
            temp='0';
            res=res+temp;
        }
        else if(x[i]=='-')
        {
            if(x[i+1]=='.')
            {
                temp='1';
                res=res+temp;
            }
            else
            {
                temp='2';
                res=res+temp;
            }
            i++;
        }
    }
    cout << res;
    return 0;
}
