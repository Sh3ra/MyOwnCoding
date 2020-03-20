#include <iostream>

using namespace std;
void initialize(int parent[],int n){
for(int i=0;i<n;i++){
    parent[i]=i;
}
}
int findParent(int parent[], int x)
{
    if(x == parent[x])
		return x;
	parent[x] = findParent(parent,parent[x]);
	return parent[x];

}

// Naive implementation of union()
void Union(int parent[], int x, int y)
{
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    parent[xset] = yset;
}
bool canReach(int parent[],int x,int y){
return findParent(parent,x)==findParent(parent,y);

}
int main()
{

    int n;
    cin>>n;
    int parent[n];
    initialize(parent,n);
    return 0;
}
