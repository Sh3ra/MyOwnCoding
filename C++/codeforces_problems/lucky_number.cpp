    #include <iostream>
    #include <bits/stdc++.h>

    using namespace std;

    int main(int argc, char const *argv[])
    {
        long long n;
        cin>>n;
        long long x=0;
        while(n)
        {
            int temp=n%10;
            if((temp==7||temp==4))
            {
                x++;
            }
            n=n/10;
        }
        if(x==0)
            {
                cout<<"NO";
                return 0;
            }
        
        while(x)
        {
            int temp=x%10;
            if(!(temp==7||temp==4))
            {
                cout<<"NO";
                return 0;
            }
            x=x/10;
        }
        cout<<"YES";
        return 0;
    }
