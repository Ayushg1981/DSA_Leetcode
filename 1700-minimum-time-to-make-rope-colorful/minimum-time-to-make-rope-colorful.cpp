class Solution {
public:
    int minCost(string colors, vector<int>& Time) {
        stack<pair<char,int>> st;
        int ans=0;
        for(int i=0;i<colors.size();i++){
            st.push({colors[i],Time[i]});
            if(st.size()>1){
                auto x=st.top();
                st.pop();
                auto y=st.top();
                if(x.first==y.first){
                    ans+=min(x.second,y.second);
                    st.push({x.first,max(x.second,y.second)});
                }
                else{
                    st.push(y);
                    st.push(x);
                }
            }
        }
        return ans;
    }
};