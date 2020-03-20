#include <iostream>
#include<queue>
#include<string>
using namespace std;

int get_beuty(priority_queue <long long>l,int x)
{
    int m=0;
    for(int i=0;i<x;i++)
    {
        m+=l.top();
        l.pop();
    }
    return m;
}
int main()
{
    int n,m,k,max_beuty=0;
    cin>>n>>m>>k;
    priority_queue<long long>temp;
    priority_queue<long long>temp2;
    string s;
    long long a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    /*for(int i=0; i<m; i++)
    {
        temp.push(a[i]);
        max_beuty=get_beuty(temp);
    }*/

    int index=0,counter=0;
    char c;
    for(int i=0; i<k; i++)
    {
        if(i!=k-1)
        {
            counter=0;
            for(int j=0; j<m; j++)
            {
                counter++;
                temp.push(a[index]);
                index++;
                if(j==m-1&&counter<k-1)
                {
                    int tempo=get_beuty(temp,m);
                    temp2=temp;
                    temp2.push(a[index]);
                    if(tempo<get_beuty(temp2,m))
                    {
                        j--;
                    }
                        temp2=priority_queue<long long>();

                }
            }

        }
        else
        {
            while(index<n)
            {
                temp.push(a[index]);
                index++;
            }

        }
        max_beuty+=get_beuty(temp,m);
        temp=priority_queue<long long>();
        if(i!=k-1){
        c=index+48;

        s.push_back(c);
        s.push_back(' ');
        }
    }
    cout<<max_beuty<<endl;
    cout<<s;
    return 0;
}
