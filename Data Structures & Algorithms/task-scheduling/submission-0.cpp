class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (int cnt : count) {
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }

        int time = 0;
        queue<pair<int, int>> q;
        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (maxHeap.empty()) {
                time = q.front().second;
            } else {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};

/*
Max-Heap
Intuition
We always want to run the task that still has the most remaining occurrences, because those are the hardest to fit into the schedule (they need more slots with cooldown gaps).
So we:
Keep a max-heap of tasks by their remaining count (most frequent on top).
At each time unit, we take the most frequent available task and run it.
After running a task, it goes into a cooldown queue with the time when it will be available again (current time + n).
When a task’s cooldown finishes, we push it back into the heap so it can be scheduled again.
If the heap is empty but some tasks are still in cooldown, we can jump the current time forward to the next time when a task becomes available.
This way we always use the CPU as efficiently as possible while respecting the cooldown.
Algorithm
Count how many times each task appears.
Build a max-heap where each entry is "remaining count" of a task (the higher the count, the higher its priority).
Create an empty queue (FIFO) to store pairs: (remaining_count_after_running, next_available_time).
Set time = 0.
While the heap is not empty or the cooldown queue is not empty:
Increment time by 1.
If the heap is not empty:
Pop the task with the largest remaining count.
"Run" it once: remaining_count -= 1.
If remaining_count > 0, push (remaining_count, time + n) into the cooldown queue (it can be used again after n units).
Check the front of the cooldown queue:
While the task at the front has next_available_time == time,
remove it from the queue and push its remaining_count back into the max-heap.
(Optional optimization)
If the heap is empty and the cooldown queue is not empty:
Let next_time be the next_available_time of the front element in the cooldown queue.
Set time = next_time (fast-forward), then process step 3 again for that time.
When both the heap and cooldown queue are empty, return time as the minimum time required to finish all tasks.


*/