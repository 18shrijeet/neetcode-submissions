class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> output(n - k + 1);
        deque<int> q;
        int l = 0, r = 0;

        while (r < n) {
            while (!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }
            q.push_back(r);

            if (l > q.front()) {
                q.pop_front();
            }

            if ((r + 1) >= k) {
                output[l] = nums[q.front()];
                l++;
            }
            r++;
        }

        return output;
    }
};
/*
Intuition
A deque helps us efficiently track the maximum inside the sliding window.
The key idea is to keep the deque storing indices of elements in decreasing order of their values.
This guarantees that:
The front of the deque always holds the index of the current window’s maximum.
Smaller elements behind a bigger one are useless (they can never become the max later),
so we remove them when pushing a new number.
If the element at the front falls out of the window, we remove it.
By maintaining this structure, each element is added and removed at most once, giving an optimal solution.
Algorithm
Use a deque to store indices of elements in decreasing order of their values.
Expand the window by moving the right pointer:
Before inserting the new index, remove indices whose values are smaller than the new value (they cannot be future maximums).
Add the new index to the deque.
If the left pointer passes the front index, remove it (it's outside the window).
Once the window reaches size k, the front of the deque represents the maximum — add it to the output.
Slide the window and repeat.
*/