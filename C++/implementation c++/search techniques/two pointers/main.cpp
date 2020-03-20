#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    int j = 0;
    int maxe = 0;
    while(j < n && i < n)
    {
        if(numbers[j] <= t)
        {
            t -= numbers[j];
            j++;
        } else {
            maxe = max(maxe,j-i);
            t += numbers[i];
            i++;
        }
    }



//////////
// sort first
/////////
// Two pointer technique based solution to find
// if there is a pair in A[0..N-1] with given sum.
bool isPairSum(A[], N, X)
{
    // represents first pointer
    int i = 0;

    // represents second pointer
    int j = N - 1;

    while (i < j) {

        // If we find a pair
        if (A[i] + A[j] == X)
            return true;

        // If sum of elements at current
        // pointers is less, we move towards
        // higher values by doing i++
        else if (A[i] + A[j] < X)
            i++;

        // If sum of elements at current
        // pointers is more, we move towards
        // lower values by doing i++
        else
            j--;
    }
    return false;
}
//////////////
//////////////
//close sum of pairs to a number
// ar1[0..m-1] and ar2[0..n-1] are two given sorted arrays
// and x is given number. This function prints the pair  from
// both arrays such that the sum of the pair is closest to x.
void printClosest(int ar1[], int ar2[], int m, int n, int x)
{
    // Initialize the diff between pair sum and x.
    int diff = INT_MAX;

    // res_l and res_r are result indexes from ar1[] and ar2[]
    // respectively
    int res_l, res_r;

    // Start from left side of ar1[] and right side of ar2[]
    int l = 0, r = n-1;
    while (l<m && r>=0)
    {
       // If this pair is closer to x than the previously
       // found closest, then update res_l, res_r and diff
       if (abs(ar1[l] + ar2[r] - x) < diff)
       {
           res_l = l;
           res_r = r;
           diff = abs(ar1[l] + ar2[r] - x);
       }

       // If sum of this pair is more than x, move to smaller
       // side
       if (ar1[l] + ar2[r] > x)
           r--;
       else  // move to the greater side
           l++;
    }

    // Print the result
    cout << "The closest pair is [" << ar1[res_l] << ", "
         << ar2[res_r] << "] \n";
}

//////////
///////////////////
//closet pairs in same array
// Prints the pair with sum closest to x
void printClosest(int arr[], int n, int x)
{
    int res_l, res_r;  // To store indexes of result pair

    // Initialize left and right indexes and difference between
    // pair sum and x
    int l = 0, r = n-1, diff = INT_MAX;

    // While there are elements between l and r
    while (r > l)
    {
       // Check if this pair is closer than the closest pair so far
       if (abs(arr[l] + arr[r] - x) < diff)
       {
           res_l = l;
           res_r = r;
           diff = abs(arr[l] + arr[r] - x);
       }

       // If this pair has more sum, move to smaller values.
       if (arr[l] + arr[r] > x)
           r--;
       else // Move to larger values
           l++;
    }

    cout <<" The closest pair is " << arr[res_l] << " and " << arr[res_r];
}

///////////////////
// Prints all triplets in arr[] with 0 sum
void findTriplets(int arr[], int n)
{
    bool found = true;
    for (int i=0; i<n-2; i++)
    {
        for (int j=i+1; j<n-1; j++)
        {
            for (int k=j+1; k<n; k++)
            {
                if (arr[i]+arr[j]+arr[k] == 0)
                {
                    cout << arr[i] << " "
                         << arr[j] << " "
                         << arr[k] <<endl;
                    found = true;
                }
            }
        }
    }

    // If no triplet with 0 sum found in array
    if (found == false)
        cout << " not exist "<<endl;

}
//////////////////
/////////////
// returns true if there is triplet with sum equal
// to 'sum' present in A[]. Also, prints the triplet
bool find3Numbers(int A[], int arr_size, int sum)
{
    int l, r;

    // Fix the first element as A[i]
    for (int i = 0; i < arr_size - 2; i++) {

        // Fix the second element as A[j]
        for (int j = i + 1; j < arr_size - 1; j++) {

            // Now look for the third number
            for (int k = j + 1; k < arr_size; k++) {
                if (A[i] + A[j] + A[k] == sum) {
                    printf("Triplet is %d, %d, %d",
                           A[i], A[j], A[k]);
                    return true;
                }
            }
        }
    }

    // If we reach here, then no triplet was found
    return false;
}

//////////////////
///////////////////
//sum of two = third
// utility function for finding
// triplet in array
void findTriplet(int arr[], int n)
{
    // sort the array
    sort(arr, arr + n);

    // for every element in arr
    // check if a pair exist(in array) whose
    // sum is equal to arr element
    for (int i = n - 1; i >= 0; i--) {
        int j = 0;
        int k = i - 1;
        while (j < k) {
            if (arr[i] == arr[j] + arr[k]) {

                // pair found
                cout << "numbers are " << arr[i] << " "
                     << arr[j] << " " << arr[k] << endl;
                return;
            } else if (arr[i] > arr[j] + arr[k])
                j += 1;
            else
                k -= 1;
        }
    }

    // no such triplet is found in array
    cout << "No such triplet exists";
}
//////////\/
////////////
void findFourElements(int A[], int n, int X)
{
  // Fix the first element and find other three
  for (int i = 0; i < n-3; i++)
  {
    // Fix the second element and find other two
    for (int j = i+1; j < n-2; j++)
    {
      // Fix the third element and find the fourth
      for (int k = j+1; k < n-1; k++)
      {
        // find the fourth
        for (int l = k+1; l < n; l++)
           if (A[i] + A[j] + A[k] + A[l] == X)
              printf("%d, %d, %d, %d", A[i], A[j], A[k], A[l]);
      }
    }
  }
}
    return 0;
}
