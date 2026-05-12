class Solution {
public:
    static bool f(vector<int>& a,vector<int>& b){
        if(a[2]>b[2]) return true;
        if(a[2]==b[2]) return a[1]<b[1];
        return false;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int sum=0;
        for(int i=0;i<tasks.size();i++){
            int x=tasks[i][0];
            int y=tasks[i][1];
            tasks[i].push_back(abs(x-y));
            sum+=x;
        }
        int ans=sum;
        sort(tasks.begin(),tasks.end(),f);
        for(int i=0;i<tasks.size();i++){
            int x=tasks[i][0];
            int y=tasks[i][1];
            if(sum>=y) sum-=x;
            else{
                ans+=y-sum;
                sum=y-x;
            }
        }
        return ans;
    }
};