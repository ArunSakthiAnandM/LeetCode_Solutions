//trivial
//Time Complexity -> O(n)
//Memory Complexity -> O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int s=nums.size();
        int a=1,c=0;
        vector<int> ans;
        for(int i=0;i<s;i++)
        {
            a = a*nums[i];
            if(nums[i] == 0)
                c++;
        }
        
        for(int i=0;i<s;i++)
        {
            if(c==0)
                ans.push_back(a/nums[i]);
            else if(c==1)
            {
                if(nums[i]!=0)
                    ans.push_back(a/nums[i]);
                else
                {
                    int temp=1;
                    for(int j=0;j<s;j++)
                        if(nums[j]!=0)
                            temp = temp*nums[j];
                    ans.push_back(temp);
                }
            }
            else
                ans.push_back(0);
        }
        return ans;
    }
};