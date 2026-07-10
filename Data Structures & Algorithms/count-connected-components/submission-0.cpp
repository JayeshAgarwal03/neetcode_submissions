class Solution {
public:
    void bfs(vector<vector<int>> &adj, vector<int> &vis, int i){
        queue<int> q;
        vis[i]=1;
        q.push(i);

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int components=0;
        for(int i=0; i<vis.size(); i++){
            if(!vis[i]){
                components++;
                bfs(adj, vis, i);
            }
        }

        return components;
    }
};
