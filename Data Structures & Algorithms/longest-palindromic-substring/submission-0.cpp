class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int resStart = 0, resLen = 0;

        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i <=2 || dp[i+1][j-1])){
                    dp[i][j]=true;
                    if(j-i+1 > resLen){
                        resLen = j-i+1;
                        resStart = i;
                    }
                }
            }
        }
        return s.substr(resStart,resLen);
    }
};
 

/*
Dynamic Programming
Intuition
Instead of re-checking the same substrings again and again, we remember whether a substring is a palindrome.
Let:
dp[i][j] = true if the substring s[i..j] is a palindrome.
A substring s[i..j] is a palindrome when:
The end characters match: s[i] == s[j]
And the inside part is also a palindrome: dp[i+1][j-1]
Special small cases: if the length is 1, 2, or 3 (j - i <= 2), then matching ends is enough because the middle is empty or a single char.
We fill dp from bottom to top (i from n-1 down to 0) so that when we compute dp[i][j], the value dp[i+1][j-1] is already known.
While filling, we keep track of the best (longest) palindrome seen so far.
Algorithm
Let n = len(s). Create a 2D table dp[n][n] initialized to false.
Keep resIdx = 0 and resLen = 0 for the best answer.
For i from n-1 down to 0:
For j from i up to n-1:
If s[i] == s[j] and (j - i <= 2 OR dp[i+1][j-1] is true):
Mark dp[i][j] = true
If (j - i + 1) is bigger than resLen, update resIdx and resLen.
Return s[resIdx : resIdx + resLen].


*/