class Solution {
public:

    void dfs(int k, vector<bool>&vis, vector<vector<int>>&adj)
    {
        vis[k]=true;
        for(auto it:adj[k])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
        }

        vector<bool>vis(n,false);
        dfs(k,vis,adj);
        vector<int>ans;


        bool canRemove = true;
        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];
           
            if (!vis[u] && vis[v]) {
                canRemove = false;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!canRemove || !vis[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};