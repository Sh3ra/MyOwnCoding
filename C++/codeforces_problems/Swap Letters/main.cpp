#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int counter=0,c1=0,c2=0;
    cin>>n;
    string s,t;
    cin>>s>>t;
    stack<pair<int,int>>vc1;
    stack<pair<int,int>>vc2;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        {
            if(s[i]=='b'){
                vc1.push(make_pair(i+1,i+1));
                c1++;
            }
            else
            {
                vc2.push(make_pair(i+1,i+1));
                c2++;
            }
        }
    }
    if((c1%2==0&&c2%2!=0)||(c1%2!=0&&c2%2==0))
    {
        cout<<-1;
        return 0;
    }
    counter+=c1/2;
    counter+=c2/2;
    int c=counter;
    if(c1%2==1)
        counter+=2;
    cout<<counter<<endl;
    for(int i=0;i<c;i++)
    {
        pair<int ,int>temp;
        if(!vc1.empty()){
        temp=vc1.top();
        vc1.pop();
        cout<<temp.first<<" "<<vc1.top().second<<endl;
        vc1.pop();
        }
        if(!vc2.empty())
        {
        temp=vc2.top();
        vc2.pop();
        cout<<temp.first<<" "<<vc2.top().second<<endl;
        vc2.pop();
        }
    }
    if(c1%2==1)
    {
        counter+=2;
        cout<<vc1.top().first<<" "<<vc1.top().second<<endl;
        cout<<vc1.top().first<<" "<<vc2.top().first<<endl;
    }


    return 0;
}
