#include<iostream>
#include <bits\stdc++.h>
#define ll long long
using namespace std;
int main(int argc, char const *argv[])
{
    freopen("task.in","r",stdin);
    int t;
    cin>>t;
    int arr[100005];
    map<int,int>m;
    while(t--){
        int n,x,ans=0;
        cin>>n;
        m.clear();
        int l=0;
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            if(m[x]!=1){
            arr[l++]=x;
            m[x]=1;
            }else{
                ans++;
            }
        }
        if(m[1]!=1){
            arr[l++]=1;
            m[1]=1;
            ans++;
        }
        sort(arr,arr+l);
        int counter=1;
        for (int i = 0; i<l-1; i++)
        {
                ans+=min(l-i-1,arr[i+1]-arr[i]-1);
                if(!(l-i-1>=arr[i+1]-arr[i]-1)){
                    break;
                }
        }
        cout<<ans<<endl;      
    }
    return 0;
}
