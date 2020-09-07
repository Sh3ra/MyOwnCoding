#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll>expect;
vector<ll>fav;

vector<ll>papa;
void init(ll n)
{
    for (int i = 0; i < n; i++)
    {
        papa.push_back(i);
    }
}
ll Find(ll j)
{
    while (papa[j]!=j)
    {
        j=papa[j];
    }
    return j;
}

void Union(ll b,ll a)
{
    papa[Find(a)]=Find(b);
}

int main(int argc, char const *argv[])
{
    ll n;cin>>n;
    init(n);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin>>x;
        x--;
        expect.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin>>x;
        if(i+x<n)
        {
            Union(i,i+x);
        }
        if(i-x>=0)
        {
            Union(i,i-x);
        }
        fav.push_back(x);
    }
    bool sad=false;
    for (int i = 0; i < n; i++)
    {
        if(Find(expect[i])!=Find(i))
           sad=true;
    }
    cout<<(sad?"NO":"YES");
    return 0;
}
