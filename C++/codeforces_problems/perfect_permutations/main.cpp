#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n%2!=0)
    {
        cout<<-1;
        return 0;
    }
    int x=2,y=1;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            cout<<x<<" ";
            x+=2;
        }
        else{

        cout<<y<<" ";
            y+=2;
        }
    }
    return 0;
}
