#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;

int main(int argc, char const *argv[]){
ll n,m,k,x,ans=0,k2,poped;
cin>>n>>m>>k;
k2=k;
queue<ll>q;
for (int i = 0; i < m; i++)
{
    cin>>x;
    q.push(x);
}
while (!q.empty())
{
    ll f=0;
   if(k>=q.front()){

   while (k>=q.front()&&!q.empty())
    {
        q.pop();
        poped++;
        f++;
    }
    k+=f;
    ans++;
   }
   else{
       k=max((long long)ceil(q.front()/k2),k+k2);
   }
}
cout<<ans;



}