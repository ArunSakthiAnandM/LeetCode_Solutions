//Using DP
//dp(i) = min(dp[i-1]+1 , i+1-m[st[i]])
//current letter included and check for prev longest substring
//m[st[i]] stores prev occurence of the current char
//Time Complexity -> O(n)
//Memory Complexity -> O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string st) {
        int s=st.size(),ans=1;
        if (s == 0)
            return 0;
        int dp[s+1];
        dp[0] = 1;
        map<char,int> m;
        m[st[0]] = 1;
        for(int i=1;i<s;i++)
        {
            dp[i] = min(dp[i-1]+1,i+1-m[st[i]]);
            m[st[i]] = i+1;
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};