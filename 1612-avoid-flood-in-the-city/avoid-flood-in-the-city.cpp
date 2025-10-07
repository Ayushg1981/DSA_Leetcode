class Solution {
public:
    typedef pair<int,int> p;
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<rains.size();i++){
            if(rains[i]!=0) mp[rains[i]].push_back(i);
        }
        vector<int> ans(rains.size(),-1);
        unordered_set<int> st;
        priority_queue<p,vector<p>,greater<p>> pq;
        for(int i=0;i<rains.size();i++){
            if(rains[i]>0){
                if(mp.find(rains[i])!=mp.end()){
                    auto x=mp[rains[i]];
                    for(int j=1;j<x.size();j++){
                        pq.push({x[j],rains[i]});
                    }
                    mp.erase(rains[i]);
                }
                if(st.find(rains[i])==st.end()){
                    st.insert(rains[i]);
                }
                else return {};
            }
            else if(pq.size()>0 && st.find(pq.top().second)!=st.end()){
                auto x=pq.top().second;
                pq.pop();
                st.erase(x);
                ans[i]=x;
            }
            else{
                if(!st.empty()){
                    ans[i]=*next(st.begin(),0);
                }
                else ans[i]=1;
            }
        }
        return ans;
    }
};