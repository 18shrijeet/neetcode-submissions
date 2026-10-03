class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = n;
        for (int i = 0; i < n; i++) {
            xorr ^= i ^ nums[i];
        }
        return xorr;
    }
};

/*
Bitwise XOR
Intuition
We are given n distinct numbers from the range [0, n], with exactly one number missing.
A very powerful observation comes from the properties of XOR (⊕):
a ⊕ a = 0 (a number cancels itself)
a ⊕ 0 = a
XOR is commutative and associative (order does not matter)
If we XOR:
all numbers from 0 to n
and all numbers present in the array
Every number that appears in both places will cancel out, leaving only the missing number.
This allows us to find the answer in linear time and constant space, without sorting or extra data structures.
*/