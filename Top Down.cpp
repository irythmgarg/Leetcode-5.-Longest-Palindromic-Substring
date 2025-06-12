class Solution {
public:
    int ans = 1;     // Stores the length of the longest palindromic substring found so far
    int start = 0;   // Stores the starting index of the longest palindromic substring
    int dp[1001][1001]; // Memoization table for storing palindrome checks

    // Helper function to check if the substring s[i..j] is a palindrome using recursion and memoization
    bool palindrome(string &s, int i, int j) {
        if (j < i) return true;  // Base case: empty or single-character substring is always a palindrome

        if (dp[i][j] != -1) return dp[i][j];  // Return cached result if available

        if (s[i] != s[j]) return dp[i][j] = 0; // If characters at ends don't match, not a palindrome

        return dp[i][j] = palindrome(s, i + 1, j - 1); // Check inner substring
    }

    // Recursive function to explore all substrings starting from index `i`
    void hlo(string s, int i) {
        if (i >= s.length()) return; // Base case: if start index exceeds string length, stop recursion

        // Try all substrings s[i..p] where p >= i
        for (int p = 0; p < s.length(); p++) {
            if (palindrome(s, i, p)) { // Check if current substring is a palindrome
                if (p - i + 1 > ans) {  // Update result if it's the longest found so far
                    ans = p - i + 1;
                    start = i;
                }
            }
        }

        // Recur for next starting index
        hlo(s, i + 1);
    }

    // Main function to be called
    string longestPalindrome(string &s) {
        memset(dp, -1, sizeof(dp)); // Initialize memoization table with -1
        hlo(s, 0);                  // Start recursion from index 0
        return s.substr(start, ans); // Extract and return the longest palindromic substring
    }
};
