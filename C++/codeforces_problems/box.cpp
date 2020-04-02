#include <iostream>
#include <bits\stdc++.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    int t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        bool arr[n+1];
        vector<ll>v;
        memset(arr,false,sizeof(arr));
        ll index=1;
        ll brr[n];
        bool done=false;
        for(int i=0;i<n;i++)
        {
            cin>>brr[i];
            if(done)continue;
            if(i==0)
            {
                v.push_back(brr[i]);
                arr[brr[i]]=true;
            }
            else {
                if(brr[i]!=brr[i-1])
                {
                    v.push_back(brr[i]);
                    arr[brr[i]]=true;
                }
                else {

                    while (arr[index])
                    {
                        index++;
                        if(index>brr[i])
                        {
                            cout<<-1;
                            done=true;
                            break;
                        }
                    }
                    if(done)continue;
                    v.push_back(index);
                    arr[index]=true;
                }
            }
        }
        if(!done)
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout<<v[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
