class Solution {
public:
    void f(vector<string>& ans,string a,int idx,string& s,unordered_set<string>& st){
        if(idx==s.size()){
            ans.push_back(a);
            return;
        }
        string x="";
        for(int i=idx;i<s.size();i++){
            x+=s[i];
            if(st.find(x)!=st.end()){
                if(a.size()==0) f(ans,x,i+1,s,st);
                else f(ans,a+" "+x,i+1,s,st);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        vector<string> ans;
        f(ans,"",0,s,st);
        return ans;
    }
};