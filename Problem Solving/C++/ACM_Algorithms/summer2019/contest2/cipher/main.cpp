#include <iostream>
        #include <stdio.h>
        #include <vector>
        #include <limits.h>
        #include <algorithm>
        #include <stack>
        #include <queue>
        #include <map>
        #include <cstring>
        #include <math.h>
        #define ll long long
   using namespace std;

   int main(int argc, char const *argv[])
   {
        int t;
        cin>>t;int you=0;
        while(t--)
        {
            you++;
            int n,m;
            cin>>n>>m;
            string a,b,c,res;
            cin>>a>>b;
            int x=((int)a[0]-'A')-((int)b[0]-'A');
            if(x<0)x+=26;
            cin>>c;
            for(int i=0;i<m;i++)
            {
                int temp=((int)(c[i]-'A')+x)%26;
                temp+='A';
                res.push_back(temp);
            }
            cout<<"Case #"<<you<<": ";
            cout<<res<<endl;
        }
       return 0;
   }
