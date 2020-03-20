#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    long long arr[n];
    long long sum_arr[n];
    std::fill_n(sum_arr, n, 0);
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<m;i++)
    {
        long x,y,z;
        cin>>x;
        switch(x)
        {
        case 1:{
            cin >>y;
            cin>>z;
            arr[y-1]=z;
            sum_arr[y-1]=-sum;
        }break;
        case 2:{
            cin>>y;
            sum+=y;
        }break;
        case 3:{
            cin>>y;
            cout<<arr[y-1]+sum+sum_arr[y-1]<<endl;
        }break;
        }
    }
    return 0;
}
