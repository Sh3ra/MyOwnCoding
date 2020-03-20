#include <iostream>
#include <iomanip>
#include <cmath>

#define PI 3.141592653589793
using namespace std;
//function get center of circle
Point circle(Point &a, Point &b, Point &c) {
    static Point ab, ac, o;
    static double a1, b1, c1, a2, b2, c2, D, D1, D2;
    //mid point ab
    ab.x = (a.x+b.x)/2;
     ab.y = (a.y+b.y)/2;
         //mid point ac
    ac.x = (a.x+c.x)/2, ac.y = (a.y+c.y)/2;

    a1 = a.x-b.x, b1 = a.y-b.y;
    c1 = a1*ab.x + b1*ab.y;
    a2 = a.x-c.x, b2 = a.y-c.y;
    c2 = a2*ac.x + b2*ac.y;
    D = a1*b2-a2*b1;
    D1 = c1*b2-c2*b1;
    D2 = a1*c2-a2*c1;
    o.x = D1/D;
    o.y = D2/D;
    return o;
}



int main(){



    double x1,y1,x2,y2,x3,y3;
    double a,b,c,S,R;

    while(cin>>x1>>y1>>x2>>y2>>x3>>y3){
        a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));

        S=0.5*fabs(x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1);
//radius of circle
        R=a*b*c/(4*S);

        cout<<fixed<<setprecision(2)<<2*PI*R<<endl;
    }

    return 0;
}
