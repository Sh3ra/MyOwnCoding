class Solution {
    #include <bits/stdc++.h>
public:
    bool checkValidString(string s) {
        int pc=0,ac=0;
        for(char x:s){
          if(x=='(')pc++;  
          else if(x==')'){
              if(pc>0)
                pc--; 
              else if(ac>0)
                  ac--;
              else return false;
          }
          else ac++; 
            //cout<<pc<<" "<<ac<<endl;
        }
        //if(pc-ac>0)return false;
         pc=0,ac=0;
        for(int i=s.size()-1;i>-1;i--){
            char x=s[i];
          if(x==')')pc++;  
          else if(x=='('){
              if(pc>0)
                pc--; 
              else if(ac>0)
                  ac--;
              else return false;
          }
          else ac++; 
            //cout<<pc<<" "<<ac<<endl;
        }
        return true;
    }
};