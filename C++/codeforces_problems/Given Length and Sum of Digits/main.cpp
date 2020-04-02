#include<iostream>
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long mulmod(long long a,long long b){return ((a%MOD)*(b%MOD))%MOD;}

int main(int argc, char const *argv[])
{
    string s;
    long long ans=1;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='m'||s[i]=='w')
        {
            cout<<0;
            return 0;
        }
        else if(s[i]=='u')
        {
            long long counter=0;
            while (s[i]=='u')
            {
                if(i<s.size())
                {
                counter++;
                i++;
                }
                else break;
            }
            long long temp;
            if(counter>2){
            temp=mulmod(counter,counter-1)/2;
            }
            else temp=counter;
            ans=mulmod(ans,temp);
        }
        else if(s[i]=='n')
        {
            long long counter=0;
            while (s[i]=='n')
            {
                if(i<s.size())
                {
                counter++;
                i++;
                }
                else break;
            }
            long long temp;
            if(counter>2){
            temp=mulmod(counter,counter-1)/2;
            }
            else temp=counter;
            ans=mulmod(ans,temp);
        }
    }
    cout<<ans;
    return 0;
}
