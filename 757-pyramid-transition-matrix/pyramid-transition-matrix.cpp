class Solution {
public:
    unordered_map<string, bool> dp; 
    bool f(int n,int i,unordered_map<string,string>& mp,vector<string>& v){
        if(n==0) return true;
        if(i == 0 && dp.count(v[n])) 
            return dp[v[n]];
        if(i>=n) return dp[v[n]]=f(n-1,0,mp,v);
        string s="";
        s+=char(v[n][i]);
        s+=char(v[n][i+1]);
        if(mp.find(s)!=mp.end()){
            string a=mp[s];
            for(int j=0;j<a.size();j++){
                v[n-1].push_back(a[j]);
                bool b=f(n,i+1,mp,v);
                if(b) return true;
                v[n-1].pop_back();
            }
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,string> mp;
        for(int i=0;i<allowed.size();i++){
            string s="";
            s+=char(allowed[i][0]);
            s+=char(allowed[i][1]);
            mp[s]+=allowed[i][2];
        }
        vector<string> v(bottom.size());
        v[bottom.size()-1]=bottom;
        return f(bottom.size()-1,0,mp,v);
    }
};