class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }

        sort(count.begin(), count.end());
        int maxf = count[25];
        int idle = (maxf - 1) * n;

        for (int i = 24; i >= 0; i--) {
            idle -= min(maxf - 1, count[i]);
        }
        return max(0, idle) + tasks.size();
    }
};

/*

Greedy
Intuition
Instead of simulating the whole schedule, we can think in terms of slots:
Let maxf be the maximum frequency of any task (e.g., if A appears 5 times, B 3 times, then maxf = 5).
Imagine placing all copies of the most frequent task in a row:
A _ _ A _ _ A _ _ A _ _ A
There are maxf - 1 gaps between these most frequent tasks.
Each gap must be at least size n to satisfy the cooldown.
So initial idle slots needed = (maxf - 1) * n.
Now, we try to fill these idle slots using other tasks:
For each other task with count c, it can fill up to min(c, maxf - 1) of these gaps (because there are only maxf - 1 gaps).
Subtract this filled amount from the idle slots.
After considering all tasks, if idle is still positive, we must add those idle slots to the total time.
If idle becomes zero or negative, it means all gaps are already filled (or over-filled) by tasks, so no extra idle time is needed.
Finally:
Total time = len(tasks) (each task takes 1 unit) + max(0, idle) (extra gaps we couldn’t fill).
Algorithm
Count how many times each task appears (frequency array or map).
Find maxf = maximum frequency among all tasks.
Compute initial idle slots: idle = (maxf - 1) * n.
For each other task with count c:
Decrease idle by min(maxf - 1, c) (this task helps fill gaps).
If idle is still positive, total time = len(tasks) + idle.
If idle is zero or negative, total time = len(tasks) (no extra idle time needed).
Return this total time.


*/