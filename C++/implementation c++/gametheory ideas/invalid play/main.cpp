
// CPP program to check if the game
// is valid
#include <bits/stdc++.h>
using namespace std;

string check_valid(int a[], int n)
{
    // starting with player P1 and P2
    // so making P3 spectator
    int spec = 3;
    for (int i = 0; i < n; i++) {

        // If spectator wins a game
        // then its not valid
        if (a[i] == spec) {
            return "Invalid";
        }

        // subtracting the current spectator
        // and winner from total sum 6 which
        // makes losing player spectator
        //sum of all numbers of player - winners-2ly barra
       // -->if 4 players (1+2+3+4)-winner-3la 7sb condition el le3b
        spec = 6 - a[i] - spec;
    }

    // None of the winner is found spectator.
    return "Valid";
}

// Driver program to test above functions
int main()
{
    int n = 4;
    int a[n] = {1, 1, 2, 3};
    cout << check_valid(a, n);
    return 0;
}
