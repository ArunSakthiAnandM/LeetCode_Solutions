//For every number added, check if prev and next elements are already present
//Increment the size accordingly
//Time Complexity -> O(n)
//Memory Complexity -> O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m,base,len;
        int s = nums.size() , ans = 0;
        for(int i=0;i<s;i++)
        {
            if(m[nums[i]] != 1)
            {
                m[nums[i]] = 1;
                if(m[nums[i]-1] == 1 && m[nums[i]+1] == 1)
                {
                    base[nums[i]] = base[nums[i]-1];
                    len[base[nums[i]]] = len[base[nums[i]-1]] + len[base[nums[i]+1]];
                    base[nums[i]+len[base[nums[i]+1]]] = base[nums[i]];
                }
                else if(m[nums[i]-1] == 1)
                    base[nums[i]] = base[nums[i]-1];
                else if(m[nums[i]+1] == 1)
                    base[nums[i]] = base[nums[i]+1];
                else
                    base[nums[i]] = nums[i];
                
                len[base[nums[i]]]++;
            }
        }
        for(int i=0;i<s;i++)
            ans = max(ans,len[nums[i]]);
        return ans;
    }
};