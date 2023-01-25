//Falling path sum at any node is independent of nodes below
//Time Complexity -> O(n^2)
//Memory Complexity -> O(1)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int ans = 10001;
        int s = m.size();
        if(s == 1) return m[0][0];
        for(int i=1;i<s;i++)
        {
            for(int j=0;j<s;j++)
            {
                if(j-1 >= 0 && j+1 <s)
                    m[i][j] = m[i][j] + min(m[i-1][j] , min(m[i-1][j-1],m[i-1][j+1]));
                else if(j-1 < 0)
                    m[i][j] = m[i][j] + min(m[i-1][j] , m[i-1][j+1]);
                else if(j+1 >= s)
                    m[i][j] = m[i][j] + min(m[i-1][j] , m[i-1][j-1]);
            }
        }
        for(int i=0;i<s;i++)
            ans = min(ans , m[s-1][i]);
        return ans;
    }
};