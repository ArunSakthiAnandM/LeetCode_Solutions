//Binary Search
// the left element is the answer whenevr it becomes less than right element
//Time Complexity -> O(logn)
//Memory Complexity -> O(1)

class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int l = 0, r = nums.size()-1, mid;
        while (l < r)
        {
            mid = l+(r-l)/2;
            if (nums[l] < nums[r]) 
                return nums[l];
            else if (nums[mid] > nums[r]) 
                l = mid+1;
            else 
                r = mid;
        }
        return nums[l];
    }
};