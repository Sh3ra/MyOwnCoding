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

int AND(int i,int j)
{
    if(i==0||j==0)
    {
        return 0;
    }
    if(i==1&&j==1)
    {
        return 1;
    }
    else return -1;
}
int OR(int i,int j)
{
    if(i==1||j==1)
    {
        return 1;
    }
    if(i==0&&j==0)
    {
        return 0;
    }
    else return -1;
}

int main(int argc, char const *argv[])
{
    int arr[32];
    int n;
    while (true)
    {
        cin>>n;
        if(n)
        {
            memset(arr,-1,sizeof(arr));
            string s;
            int i,j;
            for(int k=0;k<n;k++)
            {
                cin>>s>>i;
                if (s=="SET")
                {
                    arr[i]=1;
                }
                else if(s=="CLEAR"){
                    arr[i]=0;
                }
                else if(s== "AND"){
                    cin>>j;
                    arr[i]=AND(arr[i],arr[j]);
                }
                else if(s== "OR"){
                    cin>>j;
                    arr[i]=OR(arr[i],arr[j]);
                }
            }
            for(int k=31;k>=0;k-- )
            {
                if(arr[k]==-1)
                    cout<<"?";
                else cout<<arr[k];
            }
            cout<<endl;
        }else break;
    }
       
    return 0;
}
