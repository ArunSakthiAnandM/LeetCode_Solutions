//dp to store the max profit at a certain time
//time stamps for dp can be only the different starting and ending points
//Time Complexity -> O(1)
//Memory Complexity -> O(1)


class Solution {
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n=p.size();
        vector<vector<int>> jobs;
        for(int i=0;i<n;i++)
            jobs.push_back({e[i],s[i],p[i]});

        sort(jobs.begin(),jobs.end());
        map<int,int> dp;
        dp[jobs[0][0]] = jobs[0][2];
        for(int i=1;i<n;i++)
        {
            int j=i-1;
            while(j>=0 && dp[jobs[i][1]] == 0)
            {
                if(jobs[j][0] < jobs[i][1])
                    dp[jobs[i][1]] = dp[jobs[j][0]];
                j--;
            }
            dp[jobs[i][0]] = max(dp[jobs[i-1][0]] , jobs[i][2]+dp[jobs[i][1]]);
        }
        return dp[jobs[n-1][0]];
    }
};