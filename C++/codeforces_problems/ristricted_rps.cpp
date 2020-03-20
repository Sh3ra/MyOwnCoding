#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,a,b,c,counter=0;
        cin>>n>>a>>b>>c;
        string s;
        cin>>s;
        char arr[n];
        memset(arr,'x',sizeof arr);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R'&&b>0)
            {
                counter++;
                b--;
                arr[i]='P';
            }
            else if(s[i]=='P'&&c>0)
            {
                counter++;
                c--;
                arr[i]='S';
            }
            else if(s[i]=='S'&&a>0)
            {
                counter++;
                a--;
                arr[i]='R';
            }
        }
        int temp=n/2;
        if(n%2!=0)temp++;
        if(counter<temp)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            if(arr[i]=='x')
            {
                if(a>0)
                {
                    arr[i]='R';
                    a--;
                }
                else if(b>0)
                {
                    arr[i]='P';
                    b--;
                }
                else if(c>0)
                {
                    arr[i]='S';
                    c--;
                }
            }
                cout<<arr[i];
        }
        cout<<endl;
    }
    
    return 0;
}
