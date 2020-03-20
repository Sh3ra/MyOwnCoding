    #include<iostream>
    #include <bits\stdc++.h>
    #define ll long long
    using namespace std;
    vector<ll>factors;
    set<ll>S_factors;
    void primeFactors(ll n)  
{  
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  int si=S_factors.size();
        S_factors.insert(2);
        if(S_factors.size()>si)
       factors.push_back(2);
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
          int si=S_factors.size();
        S_factors.insert(i);
        if(S_factors.size()>si)
            factors.push_back(i);
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2){
      int si=S_factors.size();
        S_factors.insert(n);
        if(S_factors.size()>si)

            factors.push_back(n);
    }
}  
    int main(int argc, char const *argv[])
    {
        ll n;
        cin>>n;
        primeFactors(n);
        
        if(factors.size()>1)cout<<1;
        else if(factors.size()==1)cout<<factors[0];
        else cout<<n;
        return 0;
    }