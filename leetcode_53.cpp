//Using left and right pointers
//find max sum if a particular array element is definately included
//merge lists one by one with the first list
//Time Complexity -> O(s)
//Memory Complexity -> O(s)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l=0,r=1,s=nums.size(),ret=nums[0];
        int ans[s+1];
        ans[0] = nums[0];
        while(l<s&&r<s)
        {
            if(ans[r-1]>=0)
            {
                ans[r] = ans[r-1]+nums[r];
            }
            else
            {
                ans[r] = nums[r];
                l=r;
            }
            ret = max(ret,ans[r]);
            r++;
        }
        return ret;
    }
};