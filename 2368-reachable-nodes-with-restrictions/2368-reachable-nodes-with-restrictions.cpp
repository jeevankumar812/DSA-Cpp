class Solution {
public:
    int c=0;
 

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& r) {
        vector<vector<int>>adj(n);
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_set<int>s;
        for(int i=0;i<r.size();i++)
        {
            s.insert(r[i]);
        }

        vector<bool>vis(n,false);
        queue<int>q;


        if(s.find(0)!=s.end())
        {
            return 0;
        }

        int c=1;
        q.push(0);
        vis[0]=true;
        while(!q.empty())
        {
            
            auto curr=q.front();
            q.pop();
            for(auto it:adj[curr])
            {
                if(s.find(it)==s.end() && !vis[it])
                {
                    vis[it]=true;
                    q.push(it);
                    c++;
                }
            }
        }
        return c;
    }
};