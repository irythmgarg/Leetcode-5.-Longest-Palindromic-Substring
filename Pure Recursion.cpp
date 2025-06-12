class Solution {
public:
    int ans = 1;    // Stores the length of the longest palindromic substring
    int start = 0;  // Stores the starting index of the longest palindromic substring

    // Function to check if a substring s[i..j] is a palindrome
    bool palindrome(string &s, int i, int j) {
        if (j < i) return true;           // Base case: empty or invalid range is considered palindrome
        if (s[i] != s[j]) return false;   // If characters at both ends do not match, not a palindrome
        return palindrome(s, i + 1, j - 1); // Recurse on the inner substring
    }

    // Recursive function to evaluate all substrings starting from index i
    void hlo(string s, int i) {
        if (i >= s.length()) return;      // Stop when we reach the end of the string

        for (int p = 0; p < s.length(); p++) {
            // Check if the substring from i to p is a palindrome
            if (palindrome(s, i, p)) {
                // Update the longest palindrome if the current one is longer
                if (p - i + 1 > ans) {
                    ans = p - i + 1;
                    start = i;
                }
            }
        }

        // Recurse for the next starting index
        hlo(s, i + 1);
    }

    // Main function that returns the longest palindromic substring
    string longestPalindrome(string &s) {
        hlo(s, 0);                      // Start checking from index 0
        return s.substr(start, ans);   // Extract the longest palindromic substring using start and ans
    }
};
