//DFS
//Once visiting a unvisited land, visit all the connected lands and increment count
//Time Complexity -> O(mn)
//Memory Complexity -> O(mn)

class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>> &vis, int s, vector<vector<char>>& grid, int &count)
    {
        if(vis[i][j] != 1)
        {
            vis[i][j] = 1;
            if(s == 0) count++;
            
            if(i+1<grid.size() && grid[i+1][j] == '1')
                dfs(i+1,j,vis,1,grid,count);
            
            if(i-1>=0 && grid[i-1][j] == '1')
                dfs(i-1,j,vis,1,grid,count);
            
            if(j+1<grid[0].size() && grid[i][j+1] == '1')
                dfs(i,j+1,vis,1,grid,count);
            
            if(j-1>=0 && grid[i][j-1] == '1')
                dfs(i,j-1,vis,1,grid,count);
        }
    }
    
    int numIslands(vector<vector<char>>& grid)
    {
        int count = 0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis;
        vis = vector<vector<bool>>(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]=='1')
                    dfs(i,j,vis,0,grid,count);
        return count;
    }
};