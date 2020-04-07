#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,k;
    cin >> n;
    cin >> k;
    long long arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    if(k==1)
    {
        sort(arr,arr+n);
        cout << arr[0];
    }
    else if(k>2)
    {
        sort(arr,arr+n);
        cout << arr[n-1];

    }
    else
    {
        int numb;
        if(arr[0]>=arr[n-1])
        {
            numb=arr[0];
            for(int i=0;i<n;i++)
            {
                if(arr[i+1]<arr[i])
                    break;
            }
        }else{
            numb=arr[n-1];
            for(int i=n-1;i>=0;i--)
            {
                if(arr[i-1]<arr[i])
                    break;
            }
        }
        cout <<numb;
    }
    return 0;
}
