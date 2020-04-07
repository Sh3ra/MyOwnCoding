#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,xSum=0,ySum=0,zSum=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        cin >> x;
        cin >> y;
        cin >> z;
        
        xSum+=x;
        ySum+=y;
        zSum+=z;
    }
    if(xSum==0&&ySum==0&&zSum==0)
    {
        cout<< "YES";
    }
    else cout<< "NO";
    return 0;
}

