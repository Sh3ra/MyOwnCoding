    #include <bits/stdc++.h>
    typedef long long ll;
     
    using namespace std;
     
    int main(int argc, char const *argv[])
    {
        ll n, k;
        cin >> n >> k;
        ll arr[n+1];
        arr[0]=0;
        map<ll,vector<ll>>m;
        m[0].push_back(0);
        ll m1 = INT_MIN, m2 = INT_MIN, mi1 = INT_MAX, mi2 = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            arr[i] += arr[i - 1] ;
            m[arr[i]].push_back(i);
            if (arr[i] >= m1)
            {
                m2 = m1;
                m1 = arr[i];
            }
            if (arr[i] <= mi1)
            {
                mi2 = mi1;
                mi1 = arr[i];
            }
        }
        vector<ll> powers;
        powers.push_back(1);
        if (k != 1&&k!=-1)
        {
            ll x = 1;
            while (x<=max(abs(m1-mi1),m1))
            {
                x*=k;
                powers.push_back(x);
            }
            
        }
        else if(k==-1)powers.push_back(-1);
        ll ans=0;
        for (int i = n; i >0; i--)
        {
            for (int j = 0; j < powers.size(); j++)
            {
				if(m.find(arr[i]-powers[j])!=m.end()){
                vector<ll>temp=m[arr[i]-powers[j]];
                if(temp.size()==0)continue;
                ans+=(upper_bound(temp.begin(),temp.end(),i-1)-temp.begin());
				}
            }
            
        }
        cout<<ans;
    }