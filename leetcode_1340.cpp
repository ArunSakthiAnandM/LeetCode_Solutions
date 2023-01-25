//ans[l] to store the max jumps from l th step
//DP to calculate maximum
//Time Complexity -> O(n)
//Memory Complexity -> O(n)

class Solution {
public:
    int anss = 0;
    int fun(int l , vector<int> &arr , int d , vector<bool> &vis , vector<int> &ans)
    {
        if(vis[l] == 1) return ans[l];
        vis[l] = 1;
        for(int i=1;i<=d;i++)
        {
            if(l+i < arr.size() && arr[l+i]<arr[l])
                ans[l] = max(ans[l] , 1+fun(l+i,arr,d,vis,ans));
            else
                break;
        }
        for(int i=1;i<=d;i++)
        {
            if(l-i >= 0 && arr[l-i]<arr[l])
                ans[l] = max(ans[l] , 1+fun(l-i,arr,d,vis,ans));
            else
                break;
        }
        return ans[l];
    }

    int maxJumps(vector<int>& arr, int d)
    {
        int s = arr.size();
        vector<bool> vis(s,0);
        vector<int> ans(s,1);
        for(int i=0;i<s;i++)
            anss = max(anss , fun(i,arr,d,vis,ans));
        return anss;
    }
};