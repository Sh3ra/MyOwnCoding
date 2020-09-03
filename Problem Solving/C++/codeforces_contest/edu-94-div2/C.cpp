#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll x;
        cin >> x;
        char w[s.size()] = {'1'};
        memset(w, '2', sizeof(w));
        map<ll, ll> m;
        bool f = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                if (i - x >= 0)
                {
                    if (w[i - x] == 0)
                    {
                        if (m[i - x + 1] != 0)
                        {
                            m[m[i - x + 1]] = 0;
                            w[i - x] = '1';
                        }
                        else
                        {
                            f = false;
                            break;
                        }
                    }
                    w[i - x] = '1';
                }
                if (i + x < s.size())
                {
                    if (w[i + x] == 0)
                    {
                        if (m[i + x + 1] != 0)
                        {
                            m[m[i + x + 1]] = 0;
                            w[i + x] = '1';
                            if (i + x >= 0)
                            {
                                m[i - x + 1] = i + x + 1;
                                m[i + x + 1] = i - x + 1;
                            }
                        }
                        else
                        {
                            f = false;
                            break;
                        }
                    }
                    w[i + x] = '1';
                    if (i + x >= 0)
                    {
                        m[i - x + 1] = i + x + 1;
                        m[i + x + 1] = i - x + 1;
                    }
                }
                if (!((i - x >= 0) || (i + x < s.size())))
                {
                    f = false;
                    break;
                }
            }
            else
            {
                if (i - x >= 0)
                {
                    if (w[i - x] == 1)
                    {
                        if (m[i - x + 1] != 0)
                        {
                            m[m[i - x + 1]] = 0;
                            w[i - x] = '0';
                        }
                        else
                        {
                            f = false;
                            break;
                        }
                    }
                    w[i - x] = '0';
                }
                if (i + x < s.size())
                {
                    if (w[i + x] == 1)
                    {
                        if (m[i + x + 1] != 0)
                        {
                            m[m[i + x + 1]] = 0;
                            w[i + x] = '0';
                            if (i + x >= 0)
                            {
                                m[i - x + 1] = i + x + 1;
                                m[i + x + 1] = i - x + 1;
                            }
                        }
                        else
                        {
                            f = false;
                            break;
                        }
                    }
                    w[i + x] = '0';
                    if (i + x >= 0)
                    {
                        m[i - x + 1] = i + x + 1;
                        m[i + x + 1] = i - x + 1;
                    }
                }
            }
        }
        if (f)
            for (char i : w)
                {
                    if(i=='2')i='1';
                    cout<<i;
                }
        else
            cout << -1;
        cout << endl;
    }
    return 0;
}