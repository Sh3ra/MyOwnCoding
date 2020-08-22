#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll n;cin>>n;
    ll arr[n];
    //unordered_map<ll,ll>m;
    priority_queue<ll>pq;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        pq.push(arr[i]*-1);
    }
    //sort(arr,arr+n);

    ll mex=1;
    while (!pq.empty())
    {
        if(pq.top()*-1==mex)
        pq.pop();
        else
        {
            while (!pq.empty()&&pq.top()*-1<mex)
            {
                pq.pop();
            }
            if(!pq.empty())pq.pop();
            else break;
        }
        mex++;
    }
    cout<<mex;
    return 0;
}
