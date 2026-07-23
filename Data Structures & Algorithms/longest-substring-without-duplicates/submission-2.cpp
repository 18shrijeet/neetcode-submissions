class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0, j = 0;
        unordered_set<char>st;
        int maxL = 0;
        while(j<n)
        {
            while(st.contains(s[j]))
            {
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            maxL = max(maxL, j-i+1);
            j++;

        }
        return maxL;
    }
};
