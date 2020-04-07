#include<iostream>
#include <bits\stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int q;
    cin>>q;
    while (q--)
    {
        bool checker=true;
        string a,b;
        cin>>a>>b;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<a.size();i++)
        {
            if(binary_search(b.begin(),b.end(),a[i]))
            {
                checker=false;
                break;
            }
        }
        if(!checker)
        cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    
    }
    
    return 0;
}
