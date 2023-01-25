//maps
//trivial
//Time Complexity -> O(n)
//Memory Complexity -> O(1)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        map<int, int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m[nums[i]]==1)
                return true;
            m[nums[i]] = 1;
        }
        return false;
    }
};