//XOR Properties
//sum = a^b + (a&b)<<1
//       a  +     b
//do the above recursively until the carry(b) becomes 0
//When carry becomes 0, a will be the answer
//Time Complexity -> O(1)
//Memory Complexity -> O(1)

class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0)
        {
            int temp = a^b;
            b = ((a&b) & 2147483647)<<1;
            a = temp;
        }
        return a;
    }
};