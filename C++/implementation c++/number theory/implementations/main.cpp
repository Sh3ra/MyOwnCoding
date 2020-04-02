#include <iostream>
#include <bitset>
#include <bits/stdc++.h>

#define vi vector<int>
typedef long long int ll;
using namespace std;



/////////////////
////primes
/////////////////
 // compact STL for Sieve, better than vector<bool>!
ll _sieve_size; // ll is defined as: typedef long long ll;
bitset<10000010> bs; // 10^7 should be enough for most cases
vi primes; // compact list of primes in form of vector<int>
void sieve(ll upperbound) { // create list of primes in [0..upperbound]
_sieve_size = upperbound + 1; // add 1 to include upperbound
bs.set(); // set all bits to 1
bs[0] = bs[1] = 0; // except index 0 and 1
for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
// cross out multiples of i starting from i * i!
for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
primes.push_back((int)i); // add this prime to the list of primes
} } // call this method in main method
bool isPrime(ll N) { // a good enough deterministic prime tester
if (N <= _sieve_size) return bs[N]; // O(1) for small primes
for (int i = 0; i < (int)primes.size(); i++)
if (N % primes[i] == 0) return false;
return true; // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in vi "primes")^2
// inside int main()




///////////////
//gcd
///////////////
long long MOD = 1000000007;
long long fastpow(long long n,long long x)
{
    if(x == 0)
        return 1;

    if(x % 2 == 0)
    {
        long long p = fastpow(n,x/2);
        p %= MOD;
        p *= p;
        p %= MOD;
        return p;
    }
    else
        return (n * fastpow(n,x-1)) % MOD;

}


long long InverseEuler(long long n)
{
	return fastpow(n,MOD-2);
}




long long nCr(long long n, long long r)
{

 //return (fac[n]*((InverseEuler(f[r], MOD) * InverseEuler(fac[n-r], MOD)) % MOD)) % MOD;
}





double fastpowDouble(double n,ll x){
    if(x == 0)
        return 1;

    if(x%2)return n * fastpowDouble(n,x-1);

    double p = fastpowDouble(n,x/2);
  //  p %= mod;
    p *= p;
   // p %= mod;
    return p;

}




ll my_mod(ll num,ll mod){
    ll ret = num%mod;
    while(ret<0)ret+=mod;
    return ret;
}



ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }


//////////////
//primes factors
//////////////

vi primeFactors(ll N) { // remember: vi is vector<int>, ll is long long
vi factors;
ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
while (PF * PF <= N) { // stop at sqrt(N); N can get smaller
while (N % PF == 0) { N /= PF; factors.push_back(PF); } // remove PF
PF = primes[++PF_idx]; // only consider primes!
}
if (N != 1) factors.push_back(N); // special case if N is a prime
return factors; // if N does not fit in 32-bit integer and is a prime
}
//count them prime factors;
ll numPF(ll N) {
ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
while (PF * PF <= N) {
while (N % PF == 0) { N /= PF; ans++; }
PF = primes[++PF_idx];
}
if (N != 1) ans++;
return ans;
}

//totient algorithm
//count number of primes smaller than given number
ll EulerPhi(ll N) {
ll PF_idx = 0, PF = primes[PF_idx], ans = N; // start from ans = N
while (PF * PF <= N) {
if (N % PF == 0) ans -= ans / PF; // only count unique factor
while (N % PF == 0) N /= PF;
PF = primes[++PF_idx];
}
if (N != 1) ans -= ans / N; // last factor
return ans;
}

////////////
//modular inverse
ll fact[10000000];
for(ll i=2;i<=n;i++){
        fact[i]=(i*fact[i-1]%mod)%mod;
    }
ll power(ll base, ll exp) {
        if (exp == 0)
            return 1 % mod;
        if (exp & 1)
            return power(base, exp - 1) * base % mod;
        ll res = power(base, exp / 2);
        return (res*res) % mod;
}
ll nCr(ll n, ll k){
    ll numerator = fact[n];
    ll denominator = fact[n - k] ;
    denominator %= mod;
    denominator = power(denominator, mod - 2);
    return (numerator * denominator) % mod;
}
ll nPr(ll n, ll k){
    ll numerator = fact[n];
    ll denominator = fact[n - k] * fact[k];
    denominator %= mod;
    denominator = power(denominator, mod - 2);
    return (numerator * denominator) % mod;
}
///////
///extended eculids algo
// C function for extended Euclidean Algorithm
//main
int x, y;
    int a = 35, b = 15;
    int g = gcdExtended(a, b, &x, &y);
    //
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

//////
//gcd with verylarge num
ll reduceB(ll a, char b[])
{
    // Initialize result
    ll mod = 0;

    // calculating mod of b with a to make
    // b like 0 <= b < a
    for (int i=0; i<strlen(b); i++)
        mod = (mod*10 + b[i] - '0')%a;

    return mod; // return modulo
}

// This function returns GCD of 'a' and 'b'
// where b can be very large and is represented
// as a character array or string
ll gcdLarge(ll a, char b[])
{
    // Reduce 'b' (second number) after modulo with a
    ll num = reduceB(a, b);

    // gcd of two numbers
    return gcd(a, num);
}
//mmken bdl char yb2a string
int mod(string num, int a)
{
    // Initialize result
    int res = 0;

    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (int)num[i] - '0') %a;

    return res;
}
/////
example:
/*ll a = 1221;

    // second number is represented as string because
    // it can not be handled by integer data type
    char b[] = "1234567891011121314151617181920212223242526272829";
*/


//////////
//chinese remainder thereom
int inv(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
       return 0;

    // Apply extended Euclid Algorithm
    while (a > 1)
    {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
       x1 += m0;

    return x1;
}

// k is size of num[] and rem[].  Returns the smallest
// number x such that:
//  x % num[0] = rem[0],
//  x % num[1] = rem[1],
//  ..................
//  x % num[k-2] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime
// (gcd for every pair is 1)
int findMinX(int num[], int rem[], int k)
{
    // Compute product of all numbers
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];

    // Initialize result
    int result = 0;

    // Apply above formula
    for (int i = 0; i < k; i++)
    {
        int pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }

    return result % prod;
}

//////////////
//eulers totient
int phi(int n)
{
    float result = n; // Initialize result as n

    // Consider all prime factors of n and for every prime
    // factor p, multiply result with (1 - 1/p)
    for (int p = 2; p * p <= n; ++p) {

        // Check if p is a prime factor.
        if (n % p == 0) {

            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
            result *= (1.0 - (1.0 / (float)p));
        }
    }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result *= (1.0 - (1.0 / (float)n));

    return (int)result;
}

// Driver method
int main(void)
{
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    int k = sizeof(num)/sizeof(num[0]);
    cout << "x is " << findMinX(num, rem, k);
    return 0;
}
int main()
{
    sieve(10000000); // can go up to 10^7 (need few seconds)
printf("%d\n", isPrime(2147483647)); // 10-digits prime
printf("%d\n", isPrime(136117223861LL)); // not a prime, 104729*1299709

////prime factors
vi r = primeFactors(2147483647); // slowest, 2147483647 is a prime
for (vi::iterator i = r.begin(); i != r.end(); i++) printf("> %d\n", *i);
r = primeFactors(136117223861LL); // slow, 104729*1299709
for (vi::iterator i = r.begin(); i != r.end(); i++) printf("# %d\n", *i);
r = primeFactors(142391208960LL); // faster, 2^10*3^4*5*7^4*11*13
for (vi::iterator i = r.begin(); i != r.end(); i++) printf("! %d\n", *i);

    return 0;
}
