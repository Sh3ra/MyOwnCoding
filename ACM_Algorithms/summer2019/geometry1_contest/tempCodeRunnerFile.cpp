#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,r;
    cin >> n>>r;
    int  x[n];
    double  y[n];
    vector<pair<int,int>>covered_x;
    int index=-1;
    for(int i=0;i<n;i++)
        cin>>x[i];
    for(int i=0;i<n;i++)
    {
            int touched_index=-1,minY=-1,minX=-1;
            for(int j=index;j>=0;j--)
            {
                if((x[i]-r>=covered_x[j].first&&x[i]-r<=covered_x[j].second)||(x[i]+r<=covered_x[j].second&&x[i]+r>=covered_x[j].first))
                {
                    if(y[j]>minY)
                    {
                        minY=y[j];
                        touched_index=j;
                        minX=x[j];
                    }
                    else if(y[j]==minY)
                    {
                        if(abs(x[j]-x[i])<abs(minX-x[i]))
                        {
                            minY=y[j];
                            touched_index=j;
                            minX=x[j];
                        }
                    }
                }
            }
            if(touched_index!=-1)
            {
            y[i]=sqrt(4*r*r-(x[i]-x[touched_index])*(x[i]-x[touched_index]))+y[touched_index];
            covered_x.push_back(make_pair(x[i]-r,x[i]+r));
            index++;
            }
            else
            {
                y[i]=r;
                covered_x.push_back(make_pair(x[i]-r,x[i]+r));
                index++;
            }           
        }
        cout<<r<<" ";
        for(int i=1;i<n;i++)
        {
            printf("%.10lf",y[i]);
            cout<<" ";
        }
        
    
    return 0;
}
