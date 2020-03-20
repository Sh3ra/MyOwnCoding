#include<iostream>
#include <bits\stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        int arr[n],sarr[n],ax,in;
        bool check=true;
        cin>>arr[0];
        sarr[0]=arr[0];
        in=arr[0];
        ax=in;
        for(int i=1;i<n;i++)
        {
            cin>>arr[i];
            if(!(arr[i]>arr[i-1]||arr[i]==arr[i-1]))
            {
                check=false;
            }
            if(arr[i]>ax)
            ax=arr[i];
            if(arr[i]<in)
            in=arr[i];
        }    
        if(check)
        {
            cout<<0<<endl;
            continue;
        }
        int prev_s=0,prev_b=0;
        bool b_check=false;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=in&&!check)
            {
                if(!prev_s)
                prev_s=arr[i];
                else 
                {
                    if(!(prev_s<arr[i]||prev_s==arr[i]))
                    {
                        check=true;
                        break;
                    }
                    prev_s=arr[i];
                }
            }
            if(arr[i]!=ax&&!b_check)
            {
                if(!prev_b)
                prev_b=arr[i];
                else 
                {
                    if(!(prev_b<arr[i]||prev_b==arr[i]))
                    {
                        b_check=true;
                    }
                    prev_b=arr[i];
                }
            }
            if(check&&b_check)
            break;
        }
        if(!check||!b_check)
        {
            cout<<1<<endl;
        }
        else cout<<2<<endl;             
    }
    return 0;
}
