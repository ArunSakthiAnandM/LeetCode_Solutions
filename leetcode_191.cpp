//Time Complexity -> O(1)
//Memory Complexity -> O(1)

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t i = 0x00000001;
        int count = 0, ch=0;
        while(ch<32)
        {
            if(n&i != 0x00000000)
                count++;
            ch++;
            n = n>>1;
        }
        return count;
    }
};