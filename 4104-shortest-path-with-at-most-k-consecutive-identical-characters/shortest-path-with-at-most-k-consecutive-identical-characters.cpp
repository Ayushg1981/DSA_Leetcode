class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,string labels, int k) {
        vector<vector<pair<int,int>>> g(n);
        for(auto &e : edges) g[e[0]].push_back({e[1], e[2]});
        const long long INF = 1e18;
        vector<vector<long long>> dist(n,vector<long long>(k + 1, INF));
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq;
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            long long cost = cur[0];
            int u = cur[1];
            int run = cur[2];
            if(cost != dist[u][run]) continue;
            for(auto &[v,w] : g[u]) {
                int newRun;
                if(labels[v] == labels[u]) {
                    newRun = run + 1;
                    if(newRun > k) continue;
                } else {
                    newRun = 1;
                }
                long long nd = cost + w;
                if(nd < dist[v][newRun]) {
                    dist[v][newRun] = nd;
                    pq.push({nd, v, newRun});
                }
            }
        }
        long long ans = INF;

        for(int run = 1; run <= k; run++)
            ans = min(ans, dist[n - 1][run]);

        return ans == INF ? -1 : (int)ans;
    }
};