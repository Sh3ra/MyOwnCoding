#include <iostream>
#include<queue>

using namespace std;

int main()
{
    long int n,x;
    cin>>n;
    priority_queue<long int>order;
    priority_queue<long int>temp;
    queue<long int>real;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        order.push(x);
        real.push(x);
    }
    x=order.size();
    for(int i=0;i<x;i++)
    {
        if(order.top()==real.front())
        {
            cout<<order.top()<<" ";
            order.pop();
            real.pop();
            if(!temp.empty())
            {
               int y=temp.size();
                for(int j=0;j<y;j++)
                {
                if(temp.top()==order.top()){
                    cout<<temp.top()<<" ";
                    temp.pop();
                    order.pop();
                }

                }
            }
            if(i!=x-1)cout<<endl;
        }
        else
        {
            temp.push(real.front());
            real.pop();
            cout<<"We are waiting Hamada!";
            cout<<endl;
        }
    }
    x=temp.size();
    for(int i=0;i<x;i++){
        cout<<temp.top()<<" ";
        temp.pop();
        }
    return 0;
}
