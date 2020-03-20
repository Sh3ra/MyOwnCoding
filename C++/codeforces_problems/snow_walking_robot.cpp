#include <iostream>
#include <bits\stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        unordered_map<char, ll> m;
        string s;
        cin >> s;
        ll mm = INT_MAX;
        ll arr[4];
        memset(arr,0,sizeof(arr));
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'U')
            {
                m['U']++;
                arr[0]++;
            }
            if (s[i] == 'D')
            {
                m['D']++;
               arr[1]++;
            }
            if (s[i] == 'R')
            {
                m['R']++;
               arr[2]++;
            }
            if (s[i] == 'L')
            {
                m['L']++;
                arr[3]++;
            }
        }
        string ans;
        int counter=0;
        for(int i=0;i<4;i++)
        {
            if(arr[i]!=0){
                counter++;
                mm=min(mm,arr[i]);
            }
        }
        if(counter==2)mm=2;
        if (m['R'] != 0&&m['L']!=0)
            for (int i = 0; i < mm; i++)
            {
                ans+="R";
               // ans+="L";
            }
        if (m['U'] != 0&&m['D']!=0)
            for (int i = 0; i < mm; i++)
            {
                ans+="U";
            }
        if (m['R'] != 0&&m['L']!=0)
            for (int i = 0; i < mm; i++)
            {
                //ans+="R";
                ans+="L";
            }
        if (m['U'] != 0&&m['D']!=0)
            for (int i = 0; i < mm; i++)
            {
               // ans+="U";
                ans+="D";
            }
        cout <<ans.size()<< endl<<ans<<endl;
    }
}