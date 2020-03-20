// C++ program to find sum of
// bitwise ors of all subarrays.
#include <iostream>
using namespace std;

int totalSum(int a[], int n)
{
    int i, sum = 0, sum1 = 0, j;

    for (i = 0; i < n; i++)
    {

        sum1 = 0;

        // perform Bitwise OR operation
        // on all the subarray present
        // in array
        for (j = i; j < n; j++)
        {

            // OR operation
            sum1 = (sum1 | a[j]);

            // now add the sum after performing
            // the Bitwise OR operation
            sum = sum + sum1;
        }
    }

    return sum;
}

// Driver code
int main()
{
    int a[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << totalSum(a, n) << endl;
    return 0;
}
