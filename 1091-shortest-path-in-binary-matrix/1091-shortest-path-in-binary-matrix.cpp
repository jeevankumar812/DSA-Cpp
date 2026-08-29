class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        int dx[]={-1,-1,-1,0,0,1,1,1};
        int dy[]={-1,0,1,-1,1,-1,0,1};

        if(grid[0][0]==1)
        return -1;

        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        q.push({{0,0},1});
        vis[0][0]=true;
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();

            int a=curr.first.first;
            int b=curr.first.second;
            int c=curr.second;

            if(a==n-1 && b==m-1)
            {
                return c;
            }

            for(int i=0;i<8;i++)
            {
                int new_i=a+dx[i];
                int new_j=b+dy[i];

                if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && !vis[new_i][new_j]&& grid[new_i][new_j]==0)
                {
                    vis[new_i][new_j]=true;
                    q.push({{new_i,new_j},c+1});
                }
            }
        }
        return -1;
    }
};