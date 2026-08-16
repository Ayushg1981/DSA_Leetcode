class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int m=0;
        for(int i=0;i<lights.size();i++){
            m=max(m,lights[i]);
        }
        int ans=0;
        for(int i=0;i<arrivalTime.size();i++){
            if((arrivalTime[i]%period)>=m) ans=max(ans,period-arrivalTime[i]%period);
        }
        return ans;
    }
};