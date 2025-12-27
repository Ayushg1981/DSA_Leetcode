class Solution {
public:
typedef pair<long,pair<int,int>> a;
typedef pair<int,int>w;
    int mostBooked(int n, vector<vector<int>>& meetings) {
      priority_queue<a,vector<a>,greater<a>> pq;
       sort(meetings.begin(),meetings.end());
       priority_queue<w,vector<w>,greater<w>>q;
       for(int i=0;i<n;i++) q.push({i,0});
       for(int i=0;i<meetings.size();i++){
         
        while(pq.size()>0&&meetings[i][0]>=pq.top().first){
            auto e=pq.top();
            pq.pop();
            q.push({e.second.first,e.second.second});
        }
        if(pq.size()==0){
            auto x=q.top();
            q.pop();
            pq.push({meetings[i][1],{x.first,x.second+1}});
            continue;
        }
              if(q.size()>0){
                auto x=q.top();
                q.pop();
                pq.push({meetings[i][1],{x.first,x.second+1}});
              }
              else{
                auto prev=pq.top();
                pq.pop();
              pq.push({prev.first+(meetings[i][1]-meetings[i][0]),{prev.second.first,prev.second.second+1}});
              
              }
       }
       vector<pair<int,int>>v;
       int ans=INT_MAX;
       int mi=0;
       while(pq.size()>0){
           auto ele=pq.top();
           pq.pop();
           v.push_back({ele.second.first,ele.second.second});
           mi=max(mi,ele.second.second);
       }
       while(q.size()>0){
        auto ele=q.top();
           q.pop();
           v.push_back({ele.first,ele.second});
           mi=max(mi,ele.second);
       }
       for(int i=0;i<v.size();i++)
       {
           if(v[i].second==mi){
               ans=min(ans,v[i].first);
           }
       }
       return ans;
    }
};