#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    long long n;
    cin>>n;
    long long a[n];
    stack<pair<long long,long long>>s;
    int m[n];
    cin>>a[0];
    s.push(make_pair(a[0],0));
    memset(m,-1,sizeof m);
    for (int i = 1; i < n; i++)
    {
        cin>>a[i];
        if(a[i]<=s.top().first)
        {
            s.push(make_pair(a[i],i));
        }
        else {
            while(s.top().first<a[i])
            {
                m[s.top().second]=a[i];
                s.pop();
                if(s.empty())break;
            }
            s.push(make_pair(a[i],i));
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<m[i]<<" ";
    }


    return 0;
}
