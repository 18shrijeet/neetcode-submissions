class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int L = 0, R = points.size() - 1;
        int pivot = points.size();

        while (pivot != k) {
            pivot = partition(points, L, R);
            if (pivot < k) {
                L = pivot + 1;
            } else {
                R = pivot - 1;
            }
        }
        return vector<std::vector<int>>(points.begin(), points.begin() + k);
    }

private:
    int partition(vector<vector<int>>& points, int l, int r) {
        int pivotIdx = r;
        int pivotDist = euclidean(points[pivotIdx]);
        int i = l;
        for (int j = l; j < r; j++) {
            if (euclidean(points[j]) <= pivotDist) {
                swap(points[i], points[j]);
                i++;
            }
        }
        swap(points[i], points[r]);
        return i;
    }

    int euclidean(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};



/*

Quick Select
Intuition
We want the k closest points, but we do NOT need them sorted.
This is a perfect use-case for QuickSelect, the same idea used in QuickSort's partition step:
Pick a pivot point.
Partition all points into:
points closer than the pivot
points farther than the pivot
After partitioning, the pivot ends at its correct position in the final sorted order.
If the pivot ends up at index p:
If p == k, then the left side already contains the k closest points.
If p < k, search the right half.
If p > k, search the left half.
This avoids fully sorting the array and runs in average O(N) time.
Algorithm
Define a function to compute squared distance: dist = x^2 + y^2.
Use a partition function:
Choose a pivot distance.
Rearrange points so all smaller distances go left, larger go right.
Return the pivot's final index.
Maintain two pointers: L = 0, R = n - 1.
Repeatedly partition:
If pivot index p == k, stop.
If p < k, move L = p + 1.
If p > k, move R = p - 1.
After partitioning ends, the first k points in the array are the k closest.
Return those k points.

Time & Space Complexity
Time complexity: 
O
(
n
)
O(n) in average case, 
O
(
n
2
)
O(n 
2
 ) in worst case.
Space complexity: 
O
(
1
)
O(1)
*/