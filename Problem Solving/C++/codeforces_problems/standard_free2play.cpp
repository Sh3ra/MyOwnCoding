#include<iostream>
#include <bits\stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        long long h,n;
        cin>>h>>n;
        long long arr[n];
        //map<long long,long long>m;
        int c=0,index=0;
        for(int i=0;i<n;i++)
        cin>>arr[i];
        bool wait=false;
        while(h>0)
        {
            long long temp;
            if(h<=2)
            break;
            if(!wait){
                index++;
            }
            if(arr[index]==h-1)
            {
                index++;
                if(arr[index]==h-2)
                {
                    h-=2;
                    wait=false;
                }
                else {
                    c++;
                    h-=2;
                    wait=true;
                }
            }
            else {h=arr[index]+1;
            wait=true;}
        }
       
        cout<<c<<endl;
       /* while(h>0)
        {
            if(h>2)
            {
                if(m[h-1]==0)
                h--;
                else if(m[h-2]==1)
                h-=2;
                else {
                    c++;
                    h-=2;
                }              
            }
            else h-=2;
        }*/
    }
    return 0;
}