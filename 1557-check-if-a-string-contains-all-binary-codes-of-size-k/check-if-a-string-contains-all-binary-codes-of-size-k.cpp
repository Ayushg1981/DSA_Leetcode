class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size()) return false;
        unordered_set<int> st;
        int x=0;
        for(int i=0;i<k;i++){
            x=x*2;
            if(s[i]=='1') x++;
        }
        st.insert(x);
        for(int i=k;i<s.size();i++){
            x=x*2;
            if(x>=pow(2,k)){
                x-=pow(2,k);
            }
            if(s[i]=='1') x++;
            st.insert(x);
        }
        if(st.size()>=pow(2,k)) return true;
        return false;
    }
};