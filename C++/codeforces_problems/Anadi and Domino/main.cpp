#include <iostream>
#include <bits\stdc++.h>
#define ll long long
using namespace std;
bool prime[100000001];
bool prime2[100000001];
ll n;
void seive(ll n)
{
    // Create a boolean array "mark[0..n-1]" and initialize
    // all entries of it as true. A value in mark[p] will
    // finally be false if 'p' is Not a prime, else true.
    memset(prime, true, sizeof(prime));
    memset(prime2, true, sizeof(prime2));

    for (int p = 2; p < n; p++)
    {
        // If p is not changed, then it is a prime
        if (p > 1000000)
        {
            if (prime2[p - 1000000] == true)
            {
                // Update all multiples of p
                for (int i = p * 2; i < n; i += p)
                {

                    if (i < 1000000)
                        prime[i] = false;
                    else
                        prime2[i - 1000000] = false;
                }
            }
        }
        else if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i = p * 2; i < n; i += p)
                if (i < 1000000)
                    prime[i] = false;
                else
                    prime2[i - 1000000] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;
    seive(n);
    ll counter = 0, x = -1;
    for (ll i = 2; i <= n / 2; i++)
    {
        if(i<1000000)
        {

            if (prime[i])
            {
                if (n % i == 0)
                {
                    counter++;
                    x = i;
                    if (counter > 1)
                    {
                        cout << 1;
                        return 0;
                    }
                }
            }
        }
        else
        {
            if (prime2[i-1000000])
            {
                if (n % i == 0)
                {
                    counter++;
                    x = i;
                    if (counter > 1)
                    {
                        cout << 1;
                        return 0;
                    }
                }
            }
        }
    }
    if (x == -1)
        cout << n;
    else
        cout << x;
    return 0;
}
