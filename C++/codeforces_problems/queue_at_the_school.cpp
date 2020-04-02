#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,t;
    cin >> n;
    cin >> t;
    string x;
    cin >> x;
    for(int i=0;i<t;i++)
    {
        for(int index=0;index<(x.size())-1;index++)
        {
            if(x[index]=='B'&&x[index+1]=='G')
            {
                x[index]='G';
                x[index+1]='B';
                index++;
            }
        }
    }
    cout << x;
    return 0;
    
}
