#include <iostream>
#include <bits\stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    map<int, int> m;
    int in = 0, e = 0;
    vector<int> v;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            if (m[arr[i]] == 0)
            {
                in++;
                e++;
                m[arr[i]]++;
                int siz = s.size();
                s.insert(arr[i]);
                if (siz == s.size())
                {
                    cout << -1;
                    return 0;
                }
            }
            else
            {
                cout << -1;
                return 0;
            }
        }
        else
        {
            if (in == 0 || m[arr[i] * -1] == 0)
            {
                cout << -1;
                return 0;
            }
            m[arr[i] * -1]--;
            in--;
            e++;
            if (in == 0)
            {
                s.clear();
                v.push_back(e);
                e = 0;
            }
        }
    }
    if(v.size()==0||in!=0)
    {
        cout<<-1;
        return 0;
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
