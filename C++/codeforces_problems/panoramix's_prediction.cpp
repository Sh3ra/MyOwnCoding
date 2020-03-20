    #include <iostream>
    #include <bits/stdc++.h>

    using namespace std;

    int main(int argc, char const *argv[])
    {
        bool prime[51];
        prime[0]=true;
        prime[1]=true;
        for(int i=2;i<51;i++)
        {
            if (!prime[i])
            {
                int temp=2;
                while(i*temp<=50)
                {
                    prime[i*temp]=true;
                    temp++;
                }
            }
        }
        int n,m;
        cin>>n>>m;
        if(prime[m])
        {
            cout<<"NO";
            return 0;
        }
        for(int i=n;i<m;i++)
        {
            if(!prime[i])
            {
                cout<<"NO";
                return 0;
            }
        }
        cout<<"YES";
        return 0;
    }
    