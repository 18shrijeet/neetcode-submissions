class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count = 0;
        int lastEnd = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] < lastEnd){
                count++;
                lastEnd = min(lastEnd,intervals[i][1]);
            }
            else lastEnd = max(lastEnd,intervals[i][1]);
        }
        return count;
    }
};

/*
Greedy (Sort By Start)
Intuition
We want to remove the minimum number of intervals so that the remaining intervals do not overlap.
A greedy strategy works well here. After sorting intervals by their start time, we process them from left to right and always keep the interval that ends earlier when an overlap occurs.
Why this works:
When two intervals overlap, keeping the one with the smaller end time leaves more room for future intervals
Removing the interval with the larger end is always the better choice, because keeping it would block more upcoming intervals
So instead of choosing which interval to keep globally, we make a local greedy decision whenever an overlap happens.
Algorithm
Sort the intervals by their start time.
Initialize:
prevEnd as the end of the first interval
res = 0 to count how many intervals we remove
Iterate through the remaining intervals one by one:
For each interval (start, end):
If start >= prevEnd:
There is no overlap
Update prevEnd = end
Else (overlap exists):
We must remove one interval
Increment res
Keep the interval with the smaller end:
prevEnd = min(end, prevEnd)
After processing all intervals, return res



*/