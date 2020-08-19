class MagicDictionary {
public:
    /** Initialize your data structure here. */
    vector<string> v;
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        v=dict;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(int i=0;i<v.size();i++)
        {
            if(word.size()==v[i].size())
            {
                if(v[i][0]==word[0]||v[i][word.size()-1]==word[word.size()-1]||word.size()==1)
                {
                        bool mis=false,sad=true;
                        for(int j=0;j<word.size();j++)
                        {
                            if(v[i][j]!=word[j])
                            {
                                if(!mis)
                                    mis=true;
                                else {sad=false;break;}
                            }
                                
                        }
                        if(sad&&mis)
                            return true;
                                 }
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */