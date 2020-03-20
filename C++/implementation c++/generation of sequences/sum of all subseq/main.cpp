#include<bits/stdc++.h>
using namespace std;

// Return sum of sum of all sub-sequence.
int sum(int arr[], int n)
{
  int ans = 0;

  // Finding sum of the array.
  for (int i = 0; i < n; i++)
    ans += arr[i];

  return ans * pow(2, n - 1);
}

// Driver Code
int main()
{
  int arr[] = { 6, 7, 8 };
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << sum(arr, n) << endl;

  return 0;
}
