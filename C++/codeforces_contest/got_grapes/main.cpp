#include <iostream>

using namespace std;

int main()
{
    int x,y,z,g,p,b;
    cin>>x>>y>>z;
    cin>>g>>p>>b;
    if(x>g){
        cout<<"NO";
        return 0;

    }
    g=g-x;
    if(y>g+p){
        cout<<"NO";
        return 0;
    }
    if(z>g+p+b-y){
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    return 0;
}
