class Solution {
public:
    int rangeBitwiseAnd(int a, int b) {
        //if(a==0||b==0)return 0;
        while(a < b){ 
             b -= (b & -b); 
        } 
            return b; 
    }
};