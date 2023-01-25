//Priority Queue and recursive DP
//the first route that reaches n,n will be the shortest path as we use priority queue
//the max value in that path is the answer
//Time Complexity -> O(n^2)
//Memory Complexity -> O(n^2)

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        int ret = 0;
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0});
        while(vis[n-1][n-1] == 0)
        {
            int w=pq.top()[0], x=pq.top()[1], y=pq.top()[2];
            vis[x][y] = 1;
            ret = max(w,ret);
            pq.pop();
            if(x-1>=0 && vis[x-1][y] == 0)
                pq.push({grid[x-1][y],x-1,y});
            if(x+1<n && vis[x+1][y] == 0)
                pq.push({grid[x+1][y],x+1,y});
            if(y-1>=0 && vis[x][y-1] == 0)
                pq.push({grid[x][y-1],x,y-1});
            if(y+1<n && vis[x][y+1] == 0)
                pq.push({grid[x][y+1],x,y+1});
        }
        return ret;
    }
};