#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll>parent;

void init(ll n)
{
    for (int i = 0; i < n; i++)
    {
        parent.push_back(i);
    }
}

ll FIND(ll a)
{
    while (parent[a]!=a)
    {
        a=parent[a];
    }
    return a;
}

void UNION(ll a,ll b)
{
    parent[FIND(a)]=FIND(b);
}

int main(int argc, char const *argv[])
{
    ll n,m;cin>>n;
    init(n);
    m=n-1;
    stack<pair<ll,ll>>undes_r;
    for (int i = 0; i < m; i++)
    {
        ll a,b;cin>>a>>b;
        a--,b--;
        if(FIND(a)==FIND(b))
        {
            undes_r.push({a,b});
        }
        else
        {
            UNION(a,b);
        }
    }
    ll holder=-1;
    vector<vector<ll>>ans;
    for (int i = 0;i < n;i++)
    {
        if(parent[i]==i)
        {
            if(holder==-1)
            {
                holder=i;
            }
            else
            {
                vector<ll>temp;
                UNION(holder,i);
                temp.push_back(undes_r.top().first+1);
                temp.push_back(undes_r.top().second+1);
                undes_r.pop();
                temp.push_back(holder+1);
                temp.push_back(i+1);
                ans.push_back(temp);
            }
            
        }
    }
    
    cout<<ans.size()<<"\n";
    for(vector<ll>i:ans)
    {
        cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<" "<<i[3]<<"\n";
    }
    return 0;
}
