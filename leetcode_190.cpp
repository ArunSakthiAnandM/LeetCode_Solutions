//Time Complexity -> O(1)
//Memory Complexity -> O(1)

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0x00,t = 0x01,p=0x10000000;
        p = p<<1;p = p<<1;p = p<<1;
        for(int i=0;i<32;i++)
        {
            if(n&t != 0x00000000)
                ans = ans | p;
            n = n>>1;
            p = p>>1;
        }
        return ans;
    }
};