#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    int t;cin>>t;
    while (t--)
    {
        int n,m;cin>>n>>m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(i>0)cout<<"B";
                else if(j==0&&i==0)cout<<"B";
                else cout<<"W";
            }
            cout<<endl;
        }
    }
    return 0;
}
