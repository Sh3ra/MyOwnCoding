#include <iostream>

using namespace std;

int main()
{
    unsigned long long int s,e,t=0;
    unsigned long long int i=0;
    long long d;
    cin>>s>>e;
    d=s-e;
    if(d<0)d*=-1;
    for(i=i;t<d;i++)
    {
        t=(i*(i+1))/2;
    }
    if(i!=0)cout<<i-1;
    else cout<<i;
    return 0;
}
