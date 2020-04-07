#include <iostream>
#include<stack>
using namespace std;

int main()
{
    bool carry=0;
    int counter=0,r_n1,r_n2;
    string n1,n2,temp;
    cin>>n1>>n2;
    while((!n1.empty()&&!n2.empty())||carry==1){
    if(!n1.empty()&&n2.empty()){
        temp=n1.back();
        r_n1=stoi(temp);
        n1.pop_back();
        if(r_n1==9&&!n1.empty()){counter++;
        carry=1;
        }
        else carry=0;
    }else if(n1.empty()&&!n2.empty()){
        temp=n2.back();
        r_n2=stoi(temp);
        n2.pop_back();
        if(r_n2==9&&!n2.empty()){counter++;
        carry=1;
        }
        else carry=0;
    }

    else if(!n1.empty()&&!n2.empty()){
    temp=n1.back();
    r_n1=stoi(temp);
    temp=n2.back();
    r_n2=stoi(temp);
    n1.pop_back();
    n2.pop_back();
    if(carry==1){
        carry=0;
        r_n1++;
        }
    if(r_n1+r_n2>9){
        carry=1;
        counter++;
    }
    }
    else carry=0;


    }
    cout<<counter;
   return 0;
}
