#include <iostream>
#include <bits\stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    long long n, counter = 0;
    cin >> n;
    long long prefix[n];
    //map<long long,vector<long long>>indexes;
    cin >> prefix[0];
    //indexes[prefix[0]].push_back(0);
    for (int i = 1; i < n; i++)
    {
        long long x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
        //  indexes[prefix[i]].push_back(i);
    }
    if (prefix[n - 1] % 3 == 0)
    {
        long long c = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (prefix[i] * 3 == prefix[n - 1]&&i!=n-2)
            {
                counter++;
            }
             if ((prefix[i] * 3) / 2 == prefix[n-1]&&i!=0)
            {
                c += counter;
                if (prefix[i] * 3 == prefix[n - 1]&&i!=n-2)
                c--;

            }
        }
        cout << c;
    }
    else
        cout << 0;
    //int x=count(prefix,prefix+n-2,prefix[n-1]/3);
    //int y=count(prefix,prefix+n-1,(prefix[n-1]/3)*2);
    //cout<<counter;
    return 0;
}
