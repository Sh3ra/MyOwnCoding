#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int a,b,c;
    cin >> a>>b>>c;
    priority_queue<int>pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    int side1=0;
    a=pq.top();
    pq.pop();
    b=pq.top();
    pq.pop();
    side1=a-b;
    if(side1<pq.top())
    cout<<0;
    else cout<< side1-pq.top()+1;
    return 0;
}
