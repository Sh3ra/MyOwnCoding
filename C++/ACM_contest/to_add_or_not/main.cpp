#include <iostream>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
    unsigned int n,k,index_occ;
    cin>>n>>k;
    int a[n];
    for(unsigned int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    map<int,int>occ;
    int max_occ=0,o;
    unsigned int i;
        for(i=0;i<n;i++)
        {
            o=k;
            occ[a[i]]=count(a,a+n,a[i]);
            for(int j=i-1;j>=0;j--)
            {
                if(o-(a[i]-a[j])>=0&&a[i]!=a[j])
                {
                    o=o-(a[i]-a[j]);
                    occ[a[i]]++;
                }
                else break;
            }
            if(max_occ<occ[a[i]]){
                max_occ=occ[a[i]];
                index_occ=i;}
        }

    cout<<max_occ<<" "<<a[index_occ];

    return 0;
}
