#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,m;
    int k,w=0;
    cin>>n>>m>>k;
    int a[n*m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            a[w]=(i+1)*(j+1);
            w++;
        }
    }
    sort(a,a+(n*m));
    cout<<a[k-1];
    return 0;
}
