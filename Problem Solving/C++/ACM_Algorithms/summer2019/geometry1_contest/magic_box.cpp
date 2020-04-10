#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    long long vx, vy, vz;
    cin >> vx >> vy >> vz;
    long long x1, y1, z1;
    cin >> x1 >> y1 >> z1;
    long long a[6],sum=0;
    for (int i=0;i<6;i++)
        cin >> a[i];
    if(vx>x1)
    {
        sum+=a[5];
    }    
    if(vx<0)
    {
        sum+=a[4];
    }
    if(vy>y1)
    {
        sum+=a[1];
    }
    if(vy<0)
    {
        sum+=a[0];
    }
    if(vz>z1)
    {
        sum+=a[3];
    }
    if(vz<0)
    {
        sum+=a[2];
    }
    cout<< sum;

    return 0;
}
