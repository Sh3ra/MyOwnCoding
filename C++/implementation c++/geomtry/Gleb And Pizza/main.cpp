#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d1,x,y,r1,r2,i,ans=0,n;
    cin>>r1>>d1;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x>>y>>r2;
        if(sqrt(x*x+y*y)+r2<= r1 && sqrt(x*x+y*y)-r2>=r1-d1){
ans++;
        }
        else{

        }
    }
    cout<<ans;
    return 0;
}
