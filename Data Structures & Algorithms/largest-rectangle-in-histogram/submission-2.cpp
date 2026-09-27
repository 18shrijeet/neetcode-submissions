class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxA = 0;
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++)
        {
            int start = i;
            while(!st.empty() && heights[i] < st.top().second)
            {
                auto x = st.top();
                st.pop();
                maxA= max(maxA, (i-x.first)*x.second);
                start = x.first;
                
            }
            st.push({start,heights[i]});
        }
        while(!st.empty()){
            auto x = st.top();
            maxA= max(maxA, (n-x.first)*x.second);
            st.pop();
        }
        return maxA;
    }
};
