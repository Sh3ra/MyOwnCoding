#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int a,b,n;
        cin>>a>>b;

        cin>>n;
            int mid;
        while(1)
        {
            string in;
            mid=(a+b)/2;
            cout<<mid;
            cin>>in;
            if(in=="TOO_BIG")
            {
                b=mid;
            }
            else if(in=="TOO_SMALL")
            {
                a=mid;
            }
            else if(in=="CORRECT")break;
            else if(in=="WRONG_ANSWER")return 0;
        }

    }
    return 0;
}
