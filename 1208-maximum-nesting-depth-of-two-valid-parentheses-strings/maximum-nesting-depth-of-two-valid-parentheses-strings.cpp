class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        stack<int> st;
        vector<int> v(n,-1);
        for(int i=0;i<n;i++){
            if(seq[i]=='(') st.push(i);
            else{
                v[i]=st.size();
                v[st.top()]=st.size();
                st.pop();
            }
        }
        for(int i=0;i<n;i++){
            v[i]=(v[i]+1)%2;
        }
        return v;
    }
};