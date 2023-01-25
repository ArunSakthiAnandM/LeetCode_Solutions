//Using itrative dp
//trivial
//Time Complexity -> O(n)
//Memory Complexity -> O(1)

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int s=p.size();
        int ans=0,l=0,r=1;
        while(l<s && r<s)
        {
            ans = max(ans,p[r]-p[l]);
            if(p[r]-p[l]<0)
                l=r;
            r++;
        }
        return ans;
    }
};