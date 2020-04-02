#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int x,y,res=0;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            int temp;
            cin >> temp;
            if(temp)
            {
                x=i;
                y=j;
            }
        }
    }
    if(x>3)
    {
        while(x!=3)
        {
            x--;
            res++;
        }
    }
    else
    {
        while(x!=3)
        {
            x++;
            res++;
        }
    }
    if(y>3)
    {
        while(y!=3)
        {
            y--;
            res++;
        }
    }
    else   {
        while(y!=3)
        {
            y++;
            res++;
        }
    }
    cout << res;
    return 0;
}