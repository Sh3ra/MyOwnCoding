    #include <iostream>
    #include <bits/stdc++.h>

    using namespace std;

    int main(int argc, char const *argv[])
    {
        bool prime[51];
        memset(prime,false,51);
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
        /*for(int i=0;i<51;i++)
        {

            cout<<prime[i]<<endl;
        }*/
        if(prime[m]==true)
        {
            cout<<"NO";
            return 0;
        }
        for(int i=n+1;i<m;i++)
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
