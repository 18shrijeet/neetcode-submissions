class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //We initialize res to 0 and iterate through the bits of the given integer n. We extract the bit at the i-th position using ((n >> i) & 1). If it is 1, we set the corresponding bit in res at position (31 - i) using (res |= (1 << (31 - i))).
        uint32_t res = 0;
        int count=0;
        for(int i=0;i<32;i++){
            if((n>>i)&1){
                res |= (1<<(31-i));
            }
        }
        return res;
    }
};
