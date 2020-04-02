#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


const int MAX = 1e4 + 5;
int parent[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];



void initialize(){
for(int i=0;i<MAX;i++){
    parent[i]=i;
}
}
int findParent( int x)
{
    if(x == parent[x])
		return x;
	parent[x] = findParent(parent[x]);
	return parent[x];

}

// Naive implementation of union()
void union1( int x, int y)
{
    int xset = findParent( x);
    int yset = findParent( y);
    parent[xset] = yset;
}










long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(findParent(x) != findParent(y))
        {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}
