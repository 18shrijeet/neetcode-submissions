class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};


/*
Bit Manipulation (Optimal)
Intuition
We want to find the number of set bits (1s) in every number from 0 to n.
A very important observation from binary representation is:
Right-shifting a number by 1 (i >> 1) removes the least significant bit
(i & 1) tells us whether the last bit of i is 1 or 0
So, the number of set bits in i can be built from a smaller number:
setBits(i) = setBits(i >> 1) + (i & 1)
This means each result depends only on a previously computed value, making it a perfect fit for Dynamic Programming.
Algorithm
Create a DP array dp of size n + 1
dp[i] stores the number of set bits in i
Initialize dp[0] = 0
For every number i from 1 to n:
Right shift i by 1 to get i >> 1
Check the last bit using (i & 1)

Compute:
dp[i] = dp[i >> 1] + (i & 1)---------------------------*******


Return the DP array


*/