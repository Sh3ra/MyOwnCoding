#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long q,l,r;
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        cout<<p[r]-p[l];
    }
    return 0;
}