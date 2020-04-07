#include <iostream>
#include<map>
using namespace std;

int main()
{
    int n;
    cin>>n;
   unsigned long long int x,max=0;
   map <unsigned long long int,int>g;
   for(int i=0;i<n;i++)
   {
       cin>>x;
       g[x]++;
   }
   for(int i=0;i<g.size();i++)
   {
       if(g[i]>max)
        max=g[i];
   }
   cout<<max;
   return 0;
}
