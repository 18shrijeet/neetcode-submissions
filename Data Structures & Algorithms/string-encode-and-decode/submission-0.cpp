class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(string i: strs)
        {
            encoded+= to_string(i.length()) + '#' +i;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string>decoded;
        int i=0;
        while(i<s.size())
        {
            int j=i;
            while(s[j]!='#')j++;
            int l = stoi(s.substr(i,j-i));
            i=j+1;
            j=i+l;
            decoded.push_back(s.substr(i,l));
            i=j;
        }
        return decoded;
    }
};
