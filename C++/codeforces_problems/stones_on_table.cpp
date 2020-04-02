#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int counter=0;
    char now,prev;
    cin>>prev;
    for(int i=1;i<n;i++)
    {
        cin>>now;
        if(now==prev)
        {
            counter++;
        }
            prev=now;
    }
    cout<<counter;

    return 0;
}
