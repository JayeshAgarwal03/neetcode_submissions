class Solution {
public:
    void dfs(vector<vector<int>> &heights, vector<vector<int>> &ocean, int i, int j){
        ocean[i][j]=1;

        int dx[4]={-1, 0, 1, 0};
        int dy[4]={0, 1, 0, -1};

        for(int p=0; p<4; p++){
            if(i+dx[p]>=0 && i+dx[p]<heights.size() && j+dy[p]>=0 && j+dy[p]<heights[0].size()){
                if(!ocean[i+dx[p]][j+dy[p]] && heights[i+dx[p]][j+dy[p]]>=heights[i][j]){
                    dfs(heights, ocean, i+dx[p], j+dy[p]);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> pacific(heights.size(), vector<int>(heights[0].size(), 0));
        vector<vector<int>> atlantic(heights.size(), vector<int>(heights[0].size(), 0));

        for(int j=0; j<heights[0].size(); j++){
            if(!pacific[0][j]){
                dfs(heights, pacific, 0, j);
            }
        }
        for(int i=1; i<heights.size(); i++){
            if(!pacific[i][0]){
                dfs(heights, pacific, i, 0);
            }
        }

        for(int j=0; j<heights[0].size(); j++){
            if(!atlantic[heights.size()-1][j]){
                dfs(heights, atlantic, heights.size()-1, j);
            }
        }
        for(int i=0; i<heights.size(); i++){
            if(!atlantic[i][heights[0].size()-1]){
                dfs(heights, atlantic, i, heights[0].size()-1);
            }
        }
        
        vector<vector<int>> ans;
        for(int i=0; i<heights.size(); i++){
            for(int j=0; j<heights[0].size(); j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
