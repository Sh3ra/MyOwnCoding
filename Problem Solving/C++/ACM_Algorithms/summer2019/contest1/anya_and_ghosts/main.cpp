#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,m,min_numb,candle_counter=-1;
    cin >> m>> t>> min_numb;
    priority_queue<int>ghost_initials;
    priority_queue<int>ghost_initials2;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        ghost_initials.push(x);
        ghost_initials2.push(-x);
    }
    int TIME[ghost_initials.top()+2];
        std::fill_n(TIME,ghost_initials.top()+2 , -2);
    while(!ghost_initials2.empty())
    {
        TIME[ghost_initials2.top()*-1]=0;
        TIME[(ghost_initials2.top()*-1)+1]=0;
        if()
        {
            cout<<-1;
            return 0;
        }
        ghost_initials2.pop();
    }
    /*for(int i=0;i<ghost_initials.top()+2;i++)
    {
        if(TIME[i]==0)continue;

    }*/


    //cout<<candle_counter;
    return 0;
}
