class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        if(n<2) return n;
        int res = 0;

        // expand around center

        // odd length palindrome
        for(int i=0;i<n;i++){
            int l = i, r = i;
            while( l>=0 && r< n && s[l] == s[r]){
                res++;
                l--;
                r++;
            }
        }

        // even length palindrome
        for(int i = 0;i<n;i++){
            int l = i, r = i+1;
            while(l>=0 && r <n && s[l] == s[r]){
                res++;
                l--;
                r++;
            }
        }
        return res;
    }
};
