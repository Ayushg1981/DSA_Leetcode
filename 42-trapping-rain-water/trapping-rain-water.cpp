class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        for(int i=0;i<height.size();i++){
            while(!st.empty() && height[i]>height[st.top()]){
                int curr = height[st.top()];
                st.pop();
                if(st.empty()) break;
                int width = i-st.top()-1;
                ans += (min(height[st.top()],height[i])-curr)*width;
            }
            st.push(i);
        }
        return ans;
        // int n=height.size();
        // int prev[n];
        // int max=-1;
        // for(int i=0;i<n;i++){
        //     prev[i]=max;
        //     if(max<height[i]) max=height[i];
        // }
        // max=-1;
        // for(int i=n-1;i>=0;i--){
        //     if(max<prev[i]) prev[i]=max;
        //     if(max<height[i]) max=height[i];
        // }
        // int water=0;
        // for(int i=1;i<n-1;i++){
        //     if(height[i]<prev[i]){
        //         water+=prev[i]-height[i];
        //     }
        // }
        // return water;
    }
};