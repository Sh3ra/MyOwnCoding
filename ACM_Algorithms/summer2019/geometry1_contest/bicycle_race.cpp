#include <iostream>
#include <bits/stdc++.h>

#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

struct point{ double x, y;
    point() {x = y = 0.0;}
    point(double _x, double _y) : x(_x), y(_y) {}

    bool operator < (point other) const {
        if ((fabs(x - other.x) > EPS))
            return x < other.x;
        return y < other.y;
    }

    bool operator == (point other) const {
        return fabs(x-other.x) < EPS && fabs(y-other.y) < EPS;
    }
};

struct vec { double x, y; vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) { return vec(b.x - a.x, b.y - a.y); }

vec scale(vec v, double s) { return vec(v.x * s, v.y * s); }

point translate(point p, vec v) { return point(p.x + v.x , p.y + v.y); }

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

int main(int argc, char const *argv[])
{
    long long n,counter=0;
    cin >> n;
    point p1,p2,p3;
    for(int i=0;i<=n;i++)
    {
            long double x,y;
            cin>>x>>y;
            point temp (x,y);
        if(i>1)
        {
            p3=temp;
            vec v1=toVec(p1,p2);
            vec v2=toVec(p1,p3);
            if(cross(v2,v1)<0)
            {
                counter++;
            }
            p1=p2;
            p2=p3;
        }
        else
        {
            if(i==0)p1=temp;
            if(i==1)p2=temp;
        }
        
    }
    cout<<counter;
    return 0;
}
