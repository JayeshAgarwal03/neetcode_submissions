class Solution {
public:
    void topo_bfs(vector<vector<int>> &adj, vector<int> &indegrees, queue<int> &q, vector<int> &topo){
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);

            for(auto it:adj[node]){
                indegrees[it]--;
                if(indegrees[it]==0){
                    q.push(it);
                }
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses, 0);

        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
            indegrees[it[1]]++;
        }
        
        queue<int> q;

        for(int i=0; i<indegrees.size(); i++){
            if(indegrees[i]==0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        topo_bfs(adj, indegrees, q, topo);

        if(topo.size()==numCourses){
            return true;
        }
        else{
            return false;
        }
    }
};
