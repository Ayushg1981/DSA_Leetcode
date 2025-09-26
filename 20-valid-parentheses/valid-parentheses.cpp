class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s.size()%2!=0) return false;
            if(s[i]=='(') st.push(s[i]);
            else if(s[i]=='[') st.push(s[i]);
            else if(s[i]=='{') st.push(s[i]);
            else{
                if(s[i]==')' && !st.empty() && st.top()=='('){
                    st.pop();
                }
                else if(s[i]=='}' && !st.empty() && st.top()=='{'){
                    st.pop();
                }
                else if(s[i]==']' && !st.empty() && st.top()=='[') st.pop();
                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};