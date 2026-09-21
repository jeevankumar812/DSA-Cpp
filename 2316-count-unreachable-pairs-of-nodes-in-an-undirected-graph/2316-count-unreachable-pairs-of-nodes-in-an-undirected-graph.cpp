class Solution {
public:

    void dfs(int src, vector<bool>&vis, vector<vector<int>>&adj,int &cnt )
    {
        vis[src]=true;
        cnt++;
        for(auto it:adj[src])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj,cnt);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>ans;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int cnt=0;
                dfs(i,vis,adj,cnt);
                ans.push_back(cnt);
            }
        }   
        
        if(ans.size()==1)
        return 0;

        vector<int>rev;
        for(int i=0;i<ans.size();i++)
        {
            rev.push_back(ans[i]);
        }

        long long res = 0;

        long long pre=0;
        for(int x:ans)
        {
            res+=pre*x;
            pre+=x;
        }
        return res;
     
    }
};