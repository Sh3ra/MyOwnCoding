class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            bool done=false;
            for(int j=0;j<words.size();j++)
            {
                if(done)break;
                int p1=0;
                if(i!=j&&words[i].size()<words[j].size())
                {
                    for(int p2=0;p2<words[j].size();p2++)
                    {
                        if(words[i][p1]==words[j][p2]){
                            cout<<words[i]<<" "<<words[j]<<endl;
                            p1++;
                        }
                        else {if(p1)p2--;p1=0;}
                        if(p1==words[i].size()){
                            ans.push_back(words[i]);
                            done=true;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};