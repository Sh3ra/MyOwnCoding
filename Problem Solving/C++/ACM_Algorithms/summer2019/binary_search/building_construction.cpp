#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
ll calc_cost(ll h, ll heights[], ll costs[],ll n)
{
    ll total_cost = 0;
    for (int i = 0; i < n; i++)
    {
        total_cost += (abs(h - heights[i]) * costs[i]);
    }
    return total_cost;
}
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll heights[n], mh = -1;
        ll costs[n];
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
            mh = max(mh, heights[i]);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> costs[i];
        }
        ll l = 0, r = mh;
        while (l <= r)
        {
            ll mid1 = l + (r - l) / 3;
            ll mid2 = r - (r - l) / 3;
            ll c1=calc_cost(mid1,heights,costs,n);
            ll c2=calc_cost(mid2,heights,costs,n);
            if(c1<c2)
            {
                r=mid2-1;
            }
            else if(c1==c2)
            {
                l=mid1;break;
            }
            else l=mid1+1;
        }
        cout<<calc_cost(l,heights,costs,n)<<endl;
    }
    return 0;
}