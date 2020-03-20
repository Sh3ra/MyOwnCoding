#include <iostream>
        #include <stdio.h>
        #include <vector>
        #include <limits.h>
        #include <algorithm>
        #include <stack>
        #include <queue>
        #include <map>
        #include <cstring>
        #include <math.h>
        #define ll long long
        #define EPS 1e-9
        const int maxInt = 2147483647;
        const double PI = acos(-1);
        using namespace std;
        void readFromFile(){freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}
        ll arr[100005];
        ll dp[100005];
        int main(int argc, char const *argv[])
        {
            int n,x;
            cin>>n;
            for (int i = 0; i < n; i++)
            {
                cin>>x;
                arr[x]++;
            }
            dp[0]=0;
            dp[1]=arr[1];
            for (int i = 2; i < 100005; i++)
            {
                dp[i]=max(dp[i-2]+i*arr[i],dp[i-1]);
            }
            cout<<dp[100004];
            return 0;
        }