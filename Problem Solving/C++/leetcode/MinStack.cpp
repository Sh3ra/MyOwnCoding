class MinStack {
#include <bits/stdc++.h>
public:
    /** initialize your data structure here. */
    vector<int>st;
    vector<int>min_elem;
    int siz=0;
    MinStack() {
        
    }
    
    void push(int x) {
        st.push_back(x);
        siz++;
        //cout<<siz;
        if(siz>1)
            min_elem.push_back(min(min_elem[siz-1-1],x));
        else min_elem.push_back(x);
    }
    
    void pop() {
        if(siz>0){
            st.pop_back();
            min_elem.pop_back();
            siz--;
        }
    }
    
    int top() {
        if(siz>0)
            return st[siz-1];
        return NULL;
    }
    
    int getMin() {
       if(siz>0)
            return min_elem[siz-1];
       return NULL;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */