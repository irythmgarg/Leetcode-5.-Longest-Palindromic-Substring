class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n]; // dp[i][j] will be true if the substring s[i..j] is a palindrome
        int ans = 1;   // Stores the length of the longest palindromic substring found
        int start = 0; // Stores the starting index of the longest palindromic substring

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check all substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;  // If two adjacent characters are equal, it's a palindrome
                ans = 2;              // Update the max length
                start = i;            // Update the start index
            } else {
                dp[i][i + 1] = false; // Not a palindrome
            }
        }

        // Check for substrings of length 3 and more
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;  // j is the ending index of the current substring

                // Check if the current substring s[i..j] is a palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (len > ans) {
                        ans = len;    // Update maximum length
                        start = i;    // Update starting index
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }

        // Return the longest palindromic substring
        return s.substr(start, ans);
    }
};
