class TreeAncestor {
public:
    vector<vector<int>> par;
    TreeAncestor(int n, vector<int>& parent) {
        par.resize(n,vector<int>(16,-1));
        for(int i=0;i<n;i++){
            par[i][0]=parent[i];
        }
        for(int i=1;i<16;i++){
            for(int j=0;j<n;j++){
                int x=par[j][i-1];
                if(x==-1) continue;
                par[j][i]=par[x][i-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<16;i++){
            if(k&1==1){
                node=par[node][i];
            }
            if(node==-1) return -1;
            k=k>>1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */