class Solution {
public:

    void dfs(int src, vector<bool>&vis,vector<vector<int>>&adj)
    {
        vis[src]=true;
        for(auto it:adj[src])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        int c=0;

        if(edges.size()<n-1)
        {
            return -1;
        }
        
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj);
                c++;
            }
        }

       return c-1;
    }
};