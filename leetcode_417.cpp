//DP
//visit all squares by pasific and atlantic induvidually
//return the nodes visited by both
//Time Complexity -> O(mn)
//Memory Complexity -> O(mn)

class Solution {
public:
    void fun(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &mat)
    {
        if(vis[i][j] == 1) return;
        vis[i][j] = 1;
        if(i>0 && mat[i][j]<=mat[i-1][j])
            fun(i-1,j,vis,mat);
        if(j>0 && mat[i][j]<=mat[i][j-1])
            fun(i,j-1,vis,mat);
        if(i<mat.size()-1 && mat[i][j]<=mat[i+1][j])
            fun(i+1,j,vis,mat);
        if(j<mat[0].size()-1 && mat[i][j]<=mat[i][j+1])
            fun(i,j+1,vis,mat);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat)
    {
        vector<vector<int>> ret;
        int s1 = mat.size();
        int s2 = mat[0].size();
        vector<vector<bool>> p,a;
        a = p = vector<vector<bool>> (s1, vector<bool>(s2, false));
        
        for(int i=0;i<s1;i++)
            fun(i,0,p,mat);
        for(int i=0;i<s1;i++)
            fun(i,s2-1,a,mat);
        for(int j=0;j<s2;j++)
            fun(0,j,p,mat);
        for(int j=0;j<s2;j++)
            fun(s1-1,j,a,mat);
                
        for(int i=0;i<s1;i++)
            for(int j=0;j<s2;j++)
                if(p[i][j] == 1 && a[i][j] == 1)
                    ret.push_back({i,j});
        
        return ret;
    }
};