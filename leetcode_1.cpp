//Using Hashmap
//Time Complexity -> O(n)
//Memory Complexity -> O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector <int> ans;
        map <int,int> arr;
        
        for(int i=0;i<nums.size();i++)
        {
            arr.insert(pair<int, int>(nums[i],1));
            if(arr[target-nums[i]] == 1)
                for(int j=0;j<i;j++)
                    if(nums[i] == target-nums[j])
                    {
                        ans.push_back(i);
                        ans.push_back(j);
                        return ans;
                    }
        }
        return ans;
    }
};