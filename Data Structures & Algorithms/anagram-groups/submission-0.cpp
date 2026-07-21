class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() < 2) return {strs};
        unordered_map<string,vector<string>>values;
        for(string s: strs)
        {
            string t = s;
            sort(t.begin(),t.end());
            if(values.find(t) != values.end())
            {
                values[t].push_back(s);
            }
            else
            {
                values[t]={s};
            }
        }
        vector<vector<string>>ans;
        for(auto i: values)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
