class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[st.top()]=='(' && s[i]==')'){
                st.pop();
            }
            else st.push(i);
        }
        int ans=0,x=s.size();
        while(!st.empty()){
            ans=max(ans,x-st.top()-1);
            x=st.top();
            st.pop();
        }
        ans=max(ans,x);
        return ans;
    }
};