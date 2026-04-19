class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (stops > k) continue;

            for (auto& neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int edgeWeight = neighbor.second;

                // Update only if the new path is cheaper
                if (cost + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = cost + edgeWeight;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }

        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};