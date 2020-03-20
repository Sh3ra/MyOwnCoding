#include <iostream>

using namespace std;

int main()
{
    unsigned long long int n,x;
    unsigned long long int k,counter=0;
    cin>>n>>k;
    if(k==1)cout<<-1;
    else{
    while(n>=k){
        x=n/k;
        n=n%k;
        counter=counter+x;
        n=n+x;
    }
    cout<<counter;
    }
    return 0;
}
