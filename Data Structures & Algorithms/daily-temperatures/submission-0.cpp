class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int s = temperatures.size();
        vector<int>ans(s,0);
        stack<pair<int,int>>st;
        for(int i=0;i<s;i++)
        {
            while(!st.empty() && temperatures[i] > st.top().first){
                ans[st.top().second]=i-st.top().second;
                st.pop();
            }
            st.push({temperatures[i],i});
        }

        return ans;
    }
};
