//Time Complexity -> O(n)
//Memory Complexity -> O(1)

class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26);
        for(auto a:s) v[a-'a']++;
        sort(v.begin(),v.end(),greater<int>());
        int f = v[0];
        int ans = 0;
        for(auto a:v)
        {
            if(a==0) return ans;
            if(a>f) ans += min(a,a-f);
            f = min(f-1,a-1);
        }
        return ans;
    }
};