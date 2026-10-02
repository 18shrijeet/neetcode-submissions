class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int resStart = 0, resLen = 0;

        
        for(int i=0;i<n;i++){
            // odd length palindrome i,i as center and expand
            int l=i, r=i;
            while(l>=0 && r <n && s[l]==s[r]){
                if(r-l+1 > resLen){
                    resStart = l;
                    resLen = r-l+1;
                }
                l--;
                r++;
            }

        // even length palindrome i. i+1 as center and expand
            l=i, r=i+1;
            while(l>=0 && r <n && s[l]==s[r]){
                if(r-l+1 > resLen){
                    resStart = l;
                    resLen = r-l+1;
                }
                l--;
                r++;
            }
        }
        return s.substr(resStart, resLen);
    }
};
 

/*
Two Pointers
Intuition
A palindrome expands symmetrically from its center.
Every palindrome has one of two centers:
Odd length → a single character center (e.g. "racecar")
Even length → between two characters (e.g. "abba")
So instead of checking all substrings, we:
Treat every index as a possible center
Expand left and right while characters match
Track the longest palindrome found during expansion
This avoids extra space and redundant checks.
Algorithm
Initialize:
resIdx = 0 - starting index of best palindrome
resLen = 0 - length of best palindrome
For each index i in the string:
Odd-length palindrome
Set l = i, r = i
Expand while l >= 0, r < n, and s[l] == s[r]
Even-length palindrome
Set l = i, r = i + 1
Expand while l >= 0, r < n, and s[l] == s[r]
During each expansion, update resIdx and resLen if a longer palindrome is found
Return substring s[resIdx : resIdx + resLen]

*/