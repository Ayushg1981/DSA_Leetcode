class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans=-1,dis=INT_MAX;
        for(int i=0;i<drones.size();i++){
            int x=abs(target[0]-drones[i][0])+abs(target[1]-drones[i][1]);
            if(drones[i][2]>=x && dis>x){
                ans=i;
                dis=x;
            }
        }
        return ans;
    }
};