#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int binarySearch(int val,int low,int high){
while (low<high)
{
int mid=(low+high)/2;
    if(val>arr[mid]){
        low=mid+1;
    }
    else
    high=mid;
}
return arr[low];

}
int main(int argc, char const *argv[])
{
    long long n,m,x,max=0;
    cin>>n;
    vector<int>ans;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        if(arr[i]>max)max=arr[i];
    }
    sort(arr,arr+n);
    cin>>m;
    for (int  i = 0; i < m; i++)
    {
        cin>>x;
        if(x>max){
            ans.push_back(-1);
        }else{
        ans.push_back(binarySearch(x,0,n-1));
        }
    }
    for (int i = 0; i < m; i++)
    {
if(ans[i]==-1){
cout<<"Dr. Samer cannot take any offer :(."<<endl;
}else{
    cout<<ans[i]<<endl;
}
    }
    
    
    
    
    
    return 0;
}    