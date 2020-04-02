#include <iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int n,t;
    long int x;
    bool s=true,q=true,pq=true,rpq=true;
    cin>>n;
    stack< long int>st;
    queue< long int>que;
    priority_queue<long int>pque;
    priority_queue<long int>rev_pque;
    for(int i=0; i<n; i++)
    {
        cin>>t>>x;
        if(t==1)
        {
            st.push(x);
            que.push(x);
            pque.push(x);
            rev_pque.push(x*-1);
        }
        else if(t==2)
        {
            if(st.top()!=x&&s)
                s=false;
            else if(s)
                st.pop();
            if(que.front()!=x&&q)
                q=false;
            else if(q)
                que.pop();
                if(pque.top()!=x)
                pq=false;
                else if(pq)
                    pque.pop();
                if(rev_pque.top()!=x*-1)
                    rpq=false;
                else if(rpq)
                    rev_pque.pop();
        }
    }

    if((s&&q)||(s&&pq)||(q&&pq)||(s&&rpq)||(q&&rpq))
        cout<<"I'm not sure !";
    else if(s)
        cout<<"Stack !";
    else if(q)
        cout<<"Queue !";
    else if(pq||rpq)
        cout<<"Priority queue !";
    else
        cout<<"Not a Data Structure !";


    return 0;
}
