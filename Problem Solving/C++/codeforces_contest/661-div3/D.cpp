#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        ll arr[n];
        ll ans[n];
        ans[0]=1;
        string s;cin>>s;
        for (int i = 0; i < n; i++)
        {
            arr[i]=s[i]-'0';
        }
        ll curr=1;
        queue<ll>zero;
        queue<ll>one;
        for (int i = 1; i < n; i++)
        {
            if (arr[i]!=arr[i-1])
            {
                ans[i]=ans[i-1];
                if (i+1<n)
                {
                    if (arr[i]==arr[i+1])
                    {
                        if (arr[i]==0)
                            zero.push(ans[i]);
                        else one.push(ans[i]);
                    }
                }
            }
                else
                {
                    if (i==1)
                    {
                        if (arr[i-1]==0)
                        {
                            if (one.empty())
                            {
                                zero.push(ans[i-1]);
                            }
                            else
                            {
                                ans[i-1]=one.front();
                                one.pop();
                            }
                        }
                        else
                        {
                            if (zero.empty())
                            {
                                one.push(ans[i-1]);
                            }
                            else
                            {
                                ans[i-1]=zero.front();
                                zero.pop();
                            }
                        }

                    }
                    ans[i]=ans[i-1]+1;
                    if (arr[i]==0)
                    {
                        if (one.empty())
                        {
                            zero.push(ans[i]);
                        }
                        else
                        {
                            ans[i]=one.front();
                            one.pop();
                            zero.push(ans[i]);
                        }
                    }
                    else
                    {
                        if (zero.empty())
                        {
                            one.push(ans[i]);
                        }
                        else
                        {
                            ans[i]=zero.front();
                            zero.pop();
                            one.push(ans[i]);
                        }
                    }

                }
                curr=max(curr, ans[i]);
            }
            cout<<curr<<endl;
            for (int i = 0; i < n; i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }