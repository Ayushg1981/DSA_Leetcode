class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> s1,s2;
        int n=h.size();
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            while(s1.size()>0 && h[s1.top()]>=h[i]) s1.pop();
            if(s1.empty()) a[i]=-1;
            else{
                a[i]=s1.top();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(s2.size()>0 && h[s2.top()]>=h[i]) s2.pop();
            if(s2.empty()) b[i]=n;
            else{
                b[i]=s2.top();
            }
            s2.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(b[i]-a[i]-1)*h[i]);
        }
        return ans;
    }
};