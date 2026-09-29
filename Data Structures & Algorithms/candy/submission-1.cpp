class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int res = n;

        int i = 1;
        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            int inc = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                inc++;
                res += inc;
                i++;
            }

            int dec = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                dec++;
                res += dec;
                i++;
            }

            res -= min(inc, dec);
        }

        return res;
    }
};

/*
Greedy (One Pass)

Intuition
We can compute the result without storing candy counts for each child. The key insight is that ratings form a sequence of increasing and decreasing runs. For an increasing run of length k, we need 1+2+...+k extra candies above the base. For a decreasing run of length k, we also need 1+2+...+k extra candies. The peak between an increasing and decreasing run should belong to whichever run is longer.

Algorithm
Start with n candies (one per child as the base).
Iterate through the ratings, skipping equal adjacent ratings.
Count the length of each increasing run (consecutive ratings going up) and add the triangular number sum (1+2+...+inc) to the result.
Count the length of each decreasing run (consecutive ratings going down) and add its triangular sum to the result.
Subtract the minimum of the two run lengths since the peak was counted in both runs but should only be counted once (in the longer run).
Return the total.


*/