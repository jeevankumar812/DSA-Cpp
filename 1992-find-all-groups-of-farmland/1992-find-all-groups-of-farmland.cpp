class Solution {
public:
    int n,m;
    int new_i,new_j;

    void dfs(vector<vector<bool>>&vis, vector<vector<int>>&grid,int i,int j)
    {
        if(i<0 || j<0 || i>=n || j>=m||grid[i][j]==0 || vis[i][j])
        {
            return;
        }
        vis[i][j]=true;

        new_i=max(i,new_i);
        new_j=max(j,new_j);

        dfs(vis,grid,i+1,j);
        dfs(vis,grid,i,j+1);
        dfs(vis,grid,i-1,j);
        dfs(vis,grid,i,j-1);   
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        
        n=grid.size();
         m=grid[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&& grid[i][j]==1)
                {
                    new_i = i;
                    new_j = j;

                    dfs(vis, grid, i, j);

                    ans.push_back({i, j, new_i, new_j});
                }
            }
        }
        return ans;
    }
};