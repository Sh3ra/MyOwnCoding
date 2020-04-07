#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t,T=1;
    cin>>t;
    while(T<=t)
    {
        int k=0,r=0,c=0;
        int n;cin>>n;
        int arr[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin>>arr[i][j];
                if(i==j)k+=arr[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            unordered_set<int>s;
            for (int j = 0; j < n; j++)
            {
                int siz=s.size();
                s.insert(arr[i][j]);
                if(siz==s.size()){r++;
                break;}
            }
        }
        for (int i = 0; i < n; i++)
        {
            unordered_set<int>s;
            for (int j = 0; j < n; j++)
            {
                int siz=s.size();
                s.insert(arr[j][i]);
                if(siz==s.size()){c++;
                break;}
            }
        }    
        cout<<"Case #"<<T<<": "<<k<<" "<<r<<" "<<c<<endl;
        T++;
    }
    return 0;
}
