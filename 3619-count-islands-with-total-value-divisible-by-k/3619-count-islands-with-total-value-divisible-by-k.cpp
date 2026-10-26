class Solution {
public:

    void dfs(int i, int j, long long &sum , vector<vector<int>>&grid, vector<vector<bool>>&vis, int n, int m)
    {
        if(i>=n || j>=m || i<0 || j<0 || vis[i][j] || grid[i][j]==0 )
        {
            return;
        }

        sum+=(long long)grid[i][j];
        vis[i][j]=true;

        dfs(i+1,j,sum,grid,vis,n,m);
        dfs(i,j+1,sum,grid,vis,n,m);
        dfs(i-1,j,sum,grid,vis,n,m);
        dfs(i,j-1,sum,grid,vis,n,m);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]!=0)
                {
                    long long sum=0;
                    dfs(i,j,sum,grid,vis,n,m);
                    if(sum%k==0)
                    {
                        c++;
                    }
                }
            }
        }
        return c;
    }
};