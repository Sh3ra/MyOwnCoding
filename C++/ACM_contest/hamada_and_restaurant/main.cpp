#include <iostream>
#include<stack>
#include<math.h>
using namespace std;

int main()
{
    long int n;
    cin>>n;
    long long int x,index,y;
    unsigned long long int p;
    double min_d;
   stack<pair<long long int,long long int>>loc;
   stack<unsigned long long int>price;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y>>p;
        if(i==0){
            loc.push(make_pair(x,y));
            min_d=sqrt(x*x+y*y);
            price.push(p);
            index=i;
            }
            else {
                if(sqrt(x*x+y*y)<min_d){
                min_d=sqrt(x*x+y*y);
                loc.push(make_pair(x,y));
                price.push(p);
                index=i;
            }
            else if(sqrt(x*x+y*y)==min_d){
                if(p<price.top()){
                min_d=sqrt(x*x+y*y);
                loc.push(make_pair(x,y));
                price.push(p);
                index=i;
                }
                else if(p==price.top()){
                    if(x<loc.top().first){
                        min_d=sqrt(x*x+y*y);
                loc.push(make_pair(x,y));
                price.push(p);
                index=i;
                    }else if(x==loc.top().first){
                        if(y<loc.top().second){
                            min_d=sqrt(x*x+y*y);
                loc.push(make_pair(x,y));
                price.push(p);
                index=i;
                        }
                    }
                }
            }


            }
    }
    cout<<index+1;
    return 0;
}
