#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m,t;
    long int x;
    cin>>n;
    vector<long int>v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>t;
        if(t==1){
            cin>>x;
            v.push_back(x);
        }
        else if(t==2){
            cin>>x;
            v.insert(v.begin(),x);
        }
        else if(t==4)
        {
            long int temp=v[0];
            for(unsigned int i=0;i<v.size()-1;i++)
            {
                v[i]=v[i+1];

            }
            v[v.size()-1]=temp;
        }
        else if(t==3)
        {
                long int temp=v[v.size()-1];
            for(unsigned int i=v.size()-1;i>=1;i--)
            {
                v[i]=v[i-1];

            }
            v[0]=temp;
        }
    }

     cout<<v.size()<<endl;
    for(unsigned int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
    }
    return 0;
}
