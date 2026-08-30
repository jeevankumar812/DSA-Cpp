class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int c=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                long long sum=0;

                if(vis[i][j] || grid[i][j]==0)
                {
                    continue;
                }

                stack<pair<int,int>>st;
                st.push({i,j});
                vis[i][j]=true;
                while(!st.empty())
                {
                    auto curr=st.top();
                    st.pop();

                    int a=curr.first;
                    int b=curr.second;

                    sum+=grid[a][b];

                    for(int i=0;i<4;i++)
                    {
                        int new_i=a+dx[i];
                        int new_j=b+dy[i];

                        if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && !vis[new_i][new_j]&& grid[new_i][new_j]!=0)
                        {
                            vis[new_i][new_j]=true;
                            st.push({new_i,new_j});
                        }
                    }
                }  

                if(sum%k==0)
                {
                    c++;
                } 
            }
        }
        return c;
    }
};