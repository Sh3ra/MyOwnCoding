#include <iostream>

using namespace std;
	static int setBit(int S, int j) { return S | 1 << j; }

	static int clearBit(int S, int j) { return S & ~(1 << j); }

	static int toggleBit(int S, int j) { return S ^ 1 << j; }

	static bool isOn(int S, int j) { return (S & 1 << j) != 0; }

	static int turnOnLastZero(int S) { return S | S + 1; }

	static int turnOnLastConsecutiveZeroes(int S) { return S | S - 1; }

	static int turnOffLastBit(int S) { return S & S - 1; }

	static int turnOffLastConsecutiveBits(int S) { return S & S + 1; }

	static int lowBit(int S) { return S & -S; } //right most 1 in bit representation

	static int setAll(int N) { return (1 << N) - 1; }   //btwdy 2wel wa7d fl 25er b3d keda tshilo w t2lb kol 2ly b3dil

	static int modulo(int S, int N) { return (S & N - 1); }		 //S%N, N is a power of 2

	static bool isPowerOfTwo(int S) { return (S & S - 1) == 0; }

	int onescomplement(int n){return n=~n;}
	int twoscomplement(int n){return onescomplement(n)+1;}
	int count_one (int n)
        {
            int count1=0;
            while( n )
            {
            n = n&(n-1);
               count1++;
            }
            return count1;
    }

      void possibleSubsets(char A[], int N)
    {
        for(int i = 0;i < (1 << N); ++i)
        {
            for(int j = 0;j < N;++j)
                if(i & (1 << j))
                    cout << A[j] <<" ";
            cout << endl;
    }
    }
    int log2(int x)
{
    int res = 0;
    while (x >>= 1)
        res++;
    return res;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
