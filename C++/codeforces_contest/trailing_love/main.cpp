#include <iostream>

using namespace std;
long long int f(long long int n)
{

    if (n <= 1)
        return 1;
    else
        return n*f(n-1);
}
unsigned long long int base(unsigned long long x,int y)
{
    if(x<y)
        return x;
    return 10*base(x/y,y)+x%y;
}

int main()
{
    unsigned long long int n,b,counter=0;
    cin>>n>>b;
    cout<<f(n)<<endl;
    unsigned long long x=base(f(n),b);
    cout<<x<<endl;
    while(1)
    {
        if(x%10==0)
            counter++;
        else
            break;
        x=x/10;
    }
    cout<<counter;
    return 0;
}
