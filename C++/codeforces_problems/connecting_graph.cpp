#include <iostream>
#include <bits\stdc++.h>

using namespace std;
map<pair<long long, long long>, long long> p;
long long num = 0;
void get_seconds(int Arr[],int u,int v)
{
    if(u==v)
        return;
    if(u==Arr[u])
        return;
    if(num<p[make_pair(u,Arr[u])])
    {
        num=p[make_pair(u,Arr[u])];
    }
    u=Arr[u];
    get_seconds(Arr,u,v);
}
void initialize(int Arr[], int N)
{
    for (int i = 0; i < N; i++)
        Arr[i] = i;
}
//finding root of an element.
int root(int Arr[], int i)
{
    while (Arr[i] != i) //chase parent of current element until it reaches root.
    {
        i = Arr[i];
    }
    return i;
}

/*modified union function where we connect the elements by changing the root of one of the element */

int union_(int Arr[], int A, int B)
{
    int root_A = root(Arr, A);
    int root_B = root(Arr, B);
    Arr[root_A] = root_B; //setting parent of root(A) as root(B).
}
bool find(int Arr[],int A, int B)
{
    if (root(Arr,A) == root(Arr,B)) //if A and B have same root,means they are connected.
        return true;
    else
        return false;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        n++;
        int Arr[n];
        initialize(Arr,n);
        long long s = 0;
        for (int i = 0; i < m; i++)
        {
            s++;
            int q, u, v;
            cin >> q >> u >> v;
            switch (q)
            {
            case 1:
            {
                if(u<v)
                union_(Arr,u,v);
                else 
                union_(Arr,v,u);
                p[make_pair(u, v)] = s;
                p[make_pair(v, u)] = s;
            }
            break;
            case 2:
            {
                    num = 0;
                if(find(Arr,u,v))
                {
                    if(u<v)
                    get_seconds(Arr,u,v);
                    else get_seconds(Arr,v,u);
                }
                    int temp = num;
                    if (temp == 0)
                        temp = -1;
                    cout << temp << endl;
            }
            }
        }
    }
    return 0;
}
