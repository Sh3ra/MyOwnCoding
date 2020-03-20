#include <iostream>

using namespace std;
###Complete Search###
(k = size of combination,n = size of array)
vector<int> tempVec;
void solve(int index)
{
    if(tempVec.size() == k)
    {
        for(int i = 0;i < tempVec.size();i++)
            cout << tempVec[i] << " ";
        cout << endl;
        return;
    }
    if(index > n)
        return;
    tempVec.push_back(arr[index])
    solve(index + 1);
    tempVec.pop_back();
    solve(index + 1);
    return;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
