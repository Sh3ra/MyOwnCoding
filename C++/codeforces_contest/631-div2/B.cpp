#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll max1 = INT_MIN;
        bool rev=false;
        unordered_set<ll> s1;
        ll n;
        cin >> n;
        vector<ll> v(n);
        vector<ll> res;
        ll start = 0;
        bool done = false;
        for (int i = 0; i < v.size(); i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (!done)
            {
                if (s1.count(v[i]) == 1)
                {
                    if (max1 == s1.size())
                    {
                        res.push_back(start);
                        i--;
                        start = 0;
                        s1.clear();
                        max1 = INT_MIN;
                    }
                    else
                    {
                        res.clear();
                        s1.clear();
                        break;
                    }
                }
                else
                {
                    max1 = max(v[i], max1);
                    s1.insert(v[i]);
                    start++;
                }
                if(done)
                    break;
            }
        }
        if(s1.size()!=0)
        {
            if(max1==s1.size())
            {
                res.push_back(start);
                s1.clear();
                max1 = INT_MIN;
            }
            else
            {
                res.clear();
                s1.clear();
            }
        }
        if (!done)
        {
            start=0;
            for (int i = v.size()-1; i >-1; i--)
            {
                if (!done)
                {
                    if (s1.count(v[i]) == 1)
                    {
                        if (max1 == s1.size())
                        {
                            if(res.size()<2){
                                    rev=true;}
                            res.push_back(start);
                            i++;
                            start = 0;
                            s1.clear();
                            max1 = INT_MIN;
                        }
                        else
                        {
                            s1.clear();
                            done = true;
                        }
                    }
                    else
                    {
                        max1 = max(v[i], max1);
                        s1.insert(v[i]);
                        start++;
                    }
                }
            }
        }
        if(s1.size()!=0)
        {
            if(max1==s1.size())
            {
                res.push_back(start);
                s1.clear();
                max1 = INT_MIN;
            }
            else if(res.size()%2==1)
            {
                res.pop_back();
            }
        }
        if(res.size()!=2&&res.size()!=4){
            res.clear();
            done=true;
        }
        cout << res.size()/2<<endl;
        if(!done)
        {
            if(rev)
            cout<<res[1]<<" "<<res[0]<<endl;
            else             cout<<res[0]<<" "<<res[1]<<endl;

            if(res.size()==4)
                cout<<res[3]<<" "<<res[2]<<endl;
        }
    }
    return 0;
}
