#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long long n,k,counter=0;
    map<long long,long long>m;
    cin>>n>>k;
    queue<long long>q;
    for(int i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        if(counter==k)
        {   
            if(!m[x])
            {
                m[x]=1;
                q.push(x);
                m[q.front()]=0;
                q.pop();
            }
        }
        else
        {        
            if(!m[x])
            {
                m[x]=1;
                q.push(x);
                counter++;
            }
        }
    }
    cout<<counter<<endl;
    long long si=q.size();
    stack<long long>st;

    for(int i=0;i<si;i++)
    {
        st.push(q.front());
        q.pop();
    }
    for(int i=0;i<si;i++)
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}