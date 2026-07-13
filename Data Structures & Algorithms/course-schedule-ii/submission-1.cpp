class Solution {
public:
    bool topo_dfs(vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, vector<int> &topoSort, int i){
        vis[i]=1;
        pathVis[i]=1;

        for(auto it:adj[i]){
            if(!vis[it]){
                if(topo_dfs(adj, vis, pathVis, topoSort, it)){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }

        pathVis[i]=0;
        topoSort.push_back(i);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<int> topoSort;

        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        
        for(int i=0; i<vis.size(); i++){
            if(!vis[i]){
                topo_dfs(adj, vis, pathVis, topoSort, i);
            }
        }

        if(topoSort.size()==numCourses){
            return topoSort;
        }
        else{
            return {};
        }
        
    }
};
