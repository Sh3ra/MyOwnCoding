#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool check(string res)
{
    set<char> setY;
    for(int i=0;i<res.size();i++)
    setY.insert(res[i]);
    if(setY.size()==4)
        return true;
    return false;
}

int main()
{
    string res;
    int y;
    cin >> y;
    do{
       y++;
        res=to_string(y);
    }while(!check(res));
    cout <<res;
    return 0;
}
