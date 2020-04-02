#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[3][3];
    bool onOff[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            {
                int x;
                cin >>x;
                arr[i][j]=x;
                onOff[i][j]=true;
            }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int x=0;x<arr[i][j];x++)
            {
                if(onOff[i][j])
                        onOff[i][j]=false;
                    else onOff[i][j]=true;
                if(i+1<3)
                {
                    if(onOff[i+1][j])
                        onOff[i+1][j]=false;
                    else onOff[i+1][j]=true;
                }
                if(j+1<3)
                {
                    if(onOff[i][j+1])
                        onOff[i][j+1]=false;
                    else onOff[i][j+1]=true;
                }if(i-1>=0)
                {
                    if(onOff[i-1][j])
                        onOff[i-1][j]=false;
                    else onOff[i-1][j]=true;
                }if(j-1>=0)
                {
                    if(onOff[i][j-1])
                        onOff[i][j-1]=false;
                    else onOff[i][j-1]=true;
                }
            }
        }
    }
    for(int i=0;i<3;i++)
    {

        for(int j=0;j<3;j++)
        {
            cout << onOff[i][j];
        }
        cout <<endl;
    }
    return 0;
}
