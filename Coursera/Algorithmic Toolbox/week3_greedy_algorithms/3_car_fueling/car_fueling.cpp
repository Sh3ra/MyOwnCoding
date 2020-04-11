#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int ref_num=0,start=0;
    for (size_t i = 0; i < stops.size(); i++)
    {
        if(i>0&&stops[i]-stops[i-1]>tank)return -1;
        if(stops[i]-start>tank)
        {
            i--;
            start=stops[i];
            ref_num++;
        }
    }
    if(dist-stops[stops.size()-1]>tank)return -1;
    if(dist-start>tank)ref_num++;
    return ref_num;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
