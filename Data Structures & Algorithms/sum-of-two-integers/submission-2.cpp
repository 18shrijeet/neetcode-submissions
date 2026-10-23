class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0, res = 0, mask = 0xFFFFFFFF;
        for(int i=0;i<32;i++){
            int a_bit = (a >> i) & 1;
            int b_bit = (b >> i) & 1;
            int res_bit = a_bit ^ b_bit ^ carry;
            carry = a_bit + b_bit + carry;
            if(carry >=2)carry = 1;
            else carry = 0;

            if(res_bit){
                res = res | (res_bit<<i);
            }
        }
        if (res > 0x7FFFFFFF) {
            res = ~(res ^ mask);
        }
        return res;
    }
};
