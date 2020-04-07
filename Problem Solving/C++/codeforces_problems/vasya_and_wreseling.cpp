#include<iostream>
#include <bits\stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<long long>v1;
    vector<long long>v2;
    long long s1=0,s2=0;
    string last;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        if(t>0)
        {
            s1+=abs(t);
            v1.push_back(t);
            if(i==n-1)
            last="first";
        }
        else
        {
            s2+=abs(t);
            v2.push_back(abs(t));
            if(i==n-1)
            last="second";
        }
    }
    if(s1>s2)
    {
        cout<<"first";
        return 0;
    }
    else if(s1<s2)
    {
        cout<<"second";
        return 0;
    }
    else if(v1.size()>v2.size())
    {
        bool checker=true;
        for(int i=0;i<v2.size();i++)
        {
            if(v1[i]!=v2[i])
            {
                checker=false;
                break;
            }
        }
        if(checker)
        {
            cout<<"first";
            return 0;
        }
    }
    
    else if(v2.size()>v1.size())
    {
        bool checker=true;
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]!=v2[i])
            {
                checker=false;
                break;
            }
        }
        if(checker)
        {
            cout<<"second";
            return 0;
        }
    }
    int index=0;
    while (index<v1.size()&&index<v2.size())
    {
        if(v1[index]>v2[index])
        {
            cout<<"first";
            return 0;
        }
        else if(v1[index]<v2[index])
        {
            cout<<"second";
            return 0;
        }
        index++;
    }
    cout<<last;    
    return 0;
}
