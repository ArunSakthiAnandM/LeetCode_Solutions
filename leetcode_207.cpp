//DP recursion
//check for cycles in the prerequisites
//If a cycle exists, return false
//Time Complexity -> O(ns)
//Memory Complexity -> O(s)
//s is length of prerequisites

class Solution {
public:
    bool fun(int k,vector<int> adj[],vector<int> &vis)
    {
        if(vis[k] == 1)
            return false;
        else if(vis[k] == 0)
        {
            vis[k] = 1;
            int s = adj[k].size();
            for(int i=0;i<s;i++)
                if(fun(adj[k][i],adj,vis)==false)
                    return false;
        }
        vis[k] = -1;
        return true;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre)
    {
        bool ans[n];
        vector<int> vis(n,0);
        int s = pre.size();
        vector<int> adj[n];
        for(int i=0;i<s;i++)
            adj[pre[i][1]].push_back(pre[i][0]);
        
        for(int i=0;i<n;i++)
            if(fun(i,adj,vis)==false)
                return false;
        return true;
    }
};