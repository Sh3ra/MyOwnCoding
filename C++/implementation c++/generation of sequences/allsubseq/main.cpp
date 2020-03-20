#include <iostream>

using namespace std;

// Prints all subarrays in arr[0..n-1]
void subArray(int arr[], int n)
{
    // Pick starting point
    for (int i=0; i <n; i++)
    {
        // Pick ending point
        for (int j=i; j<n; j++)
        {
            // Print subarray between current starting
            // and ending points
            for (int k=i; k<=j; k++)
                cout << arr[k] << " ";

            cout << endl;
        }
    }
}
/*All Non-empty Subarrays
1
1 2
1 2 3
1 2 3 4
2
2 3
2 3 4
3
3 4
4 */
///////////////
//generate subsequences
///////////num of non empty subbsequ = (2n-1)
void printSubsequences(int arr[], int n)
{
    /* Number of subsequences is (2**n -1)*/
    unsigned int opsize = pow(2, n);

    /* Run from counter 000..1 to 111..1*/
    for (int counter = 1; counter < opsize; counter++)
    {
        for (int j = 0; j < n; j++)
        {
            /* Check if jth bit in the counter is set
                If set then print jth element from arr[] */
            if (counter & (1<<j))
                cout << arr[j] << " ";
        }
        cout << endl;
    }
}
/*All Non-empty Subsequences
1
2
1 2
3
1 3
2 3
1 2 3
4
1 4
2 4
1 2 4
3 4
1 3 4
2 3 4
1 2 3 4*/

// Driver program
int main()
{

    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "All Non-empty Subarrays\n";
    subArray(arr, n);
    return 0;
}
