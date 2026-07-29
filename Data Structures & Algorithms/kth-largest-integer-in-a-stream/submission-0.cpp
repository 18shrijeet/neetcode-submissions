class KthLargest {
private:
    int s;
    priority_queue<int,vector<int>,greater<int>>pq;
public:
    KthLargest(int k, vector<int>& nums) {
        s=k;
        for(int i: nums)add(i);
    }
    
    int add(int val) {
        if(pq.size()==s)
        {
            if(pq.top() < val)
            {
                pq.pop();
                pq.push(val);
            }
        }
        else pq.push(val);
        return pq.top();
    }
};
