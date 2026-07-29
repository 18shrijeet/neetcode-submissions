class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)return stones[0];
        priority_queue<int,vector<int>>maxheap(stones.begin(),stones.end());
        while(!(maxheap.size() <= 1))
        {
            int first = maxheap.top();
            maxheap.pop();
            int sec = maxheap.top();
            maxheap.pop();

            if(first==sec) continue;
            else maxheap.push(first-sec);
        }
        if(maxheap.size())
        {
            return maxheap.top();
        }
        return 0;
    }
};
