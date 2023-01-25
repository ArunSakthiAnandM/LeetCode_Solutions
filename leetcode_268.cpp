//XOR Properties
// k ^ k = 1
// k ^ 1 = k
//Time Complexity -> O(n)
//Memory Complexity -> O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        int ans=n;
        for(int i=0;i<n;i++)
        {
            ans = ans^i;
            ans = ans^nums[i];
        }
        return ans;
    }
};