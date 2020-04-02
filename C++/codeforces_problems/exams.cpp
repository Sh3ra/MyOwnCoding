#include<iostream>
#include <bits\stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<pair<ll ,ll>>v;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    ll day;
    day=v[0].second;
    for(int i=1;i<n;i++)
    {
        if(v[i].second>=day)
        day=v[i].second;
        else day=v[i].first;
    }
    cout<<day;
    return 0;
}
