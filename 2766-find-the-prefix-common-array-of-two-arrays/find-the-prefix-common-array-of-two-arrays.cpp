class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> a(A.size(),0);
        vector<int> ans(A.size(),0);
        int x=0;
        for(int i=0;i<A.size();i++){
            a[A[i]-1]++;
            if(a[A[i]-1]==2) x++;
            a[B[i]-1]++;
            if(a[B[i]-1]==2) x++;
            ans[i]=x;
        }
        return ans;
    }
};