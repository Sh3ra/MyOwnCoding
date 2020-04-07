#include <iostream>
#include <bits/stdc++.h>
#include <cmath> 
#include <iomanip> 
#include  <tgmath.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, vb, vs;
    cin >> n >> vb >> vs;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int xu, yu;
    cin >> xu >> yu;
    long double min_timer = INT_MAX;
    int min_index = 0;
    for (int i = 1; i < n; i++)
    {
        long double counter = 0;
        counter += arr[i] / (vb * 1.0);
        long double temp1,temp2;
        temp1=arr[i]-xu;
        temp1*=temp1;
        temp2=yu*yu;
        long double dis = sqrtl(temp1+temp2);
        counter += dis / (vs * 1.0);
        if (counter <= min_timer||i==1)
        {
            min_timer = counter;
            min_index = i + 1;
        }
        else break;
    }
    cout << min_index;
    return 0;
}
