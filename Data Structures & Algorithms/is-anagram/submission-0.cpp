class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(n!=m)return false;
        vector<int>store(26,0);
        for(char c: s)
        {
            store[c - 'a']++;
        }
        for(char c: t)
        {
            store[c - 'a']--;
        }
        for(int i: store)
        {
            if(i > 0) return false;
        }
        return true;
    }
};
