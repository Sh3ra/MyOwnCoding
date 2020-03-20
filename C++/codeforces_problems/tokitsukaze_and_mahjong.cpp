#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string>in;
    set<string>se;
    string temp;
    int res=2;
    for(int i=0;i<3;i++)
    {
        cin>> temp;
        in.push_back(temp);
        se.insert(temp);
        temp.clear();
    }
    if(se.size()==1)
    {
        cout<< 0;
        return 0;
    }
    if(se.size()==2)
    {
        res=1;
        cout<< res;
        return 0;
    }
    sort(in.begin(),in.end());
    int counter=2;
     if (in[0][0]==in[1][0]-1&&in[1][1]==in[0][1]&&in[1][0]==in[2][0]-1&&in[1][1]==in[2][1])
    {
            cout<<0;
            return 0;
     }
    
    if((in[0][0]==in[1][0]-2&&in[0][1]==in[1][1])
    ||( in[0][0]==in[2][0]-2&&in[0][1]==in[2][1])||
    ( in[1][0]==in[2][0]-2&&in[1][1]==in[2][1]))        {
            counter=1;
    }

    if((in[0][0]==in[1][0]-1&&in[0][1]==in[1][1])
    ||( in[0][0]==in[2][0]-1&&in[0][1]==in[2][1])||
    ( in[1][0]==in[2][0]-1&&in[1][1]==in[2][1]))        {
            counter=1;
    }
     
    cout<< counter;
    return 0;
}
