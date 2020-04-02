#include<iostream>
#include <bits\stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,r;
        cin>>n>>r;
        vector<int>arr;
        set<int>s;
        for(int i=0;i<n;i++)
        {
            int temp,siz;
            cin>>temp;
            siz=s.size();
            s.insert(temp);
            if(s.size()>siz)
            arr.push_back(temp);
        }
        sort(arr.begin(),arr.end());
        int counter=0;
        bool done=false;
        for(int i=arr.size()-1;i>=0;i--)
        {
            int x=ceil(arr[i]/(float)r);
            if(ceil(arr[i]/(float)r)>counter)
            {
                counter++;
            }
            else {
                cout<<counter<<endl;
                done=true;
                break;
            }
        }
        if(!done)
       cout<<counter<<endl;
    }
    return 0;
}