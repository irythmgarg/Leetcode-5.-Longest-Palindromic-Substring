# Leetcode-5.-Longest-Palindromic-Substring
# 🌸 Longest Palindromic Substring (LPS)

Welcome to the **Longest Palindromic Substring** problem guide! 🌟 This classic problem helps strengthen your understanding of dynamic programming, recursion, and string manipulation.

---

## 📝 Problem Statement

Given a string `s`, return the **longest substring** that is a palindrome.

### 💡 Example:

Input: `s = "babad"`
Output: `"bab"` or `"aba"`

---

## 🔁 Approach 1: Pure Recursion 🔄

### 💡 Idea:

* Check every possible substring starting at each index.
* For each substring, recursively check if it is a palindrome.
* Keep track of the maximum length and starting index.

### ❌ Drawback:

* **Very inefficient** due to repeated computations.

### 🧮 Complexity:

* Time: **O(2^n)**
* Space: **O(n)** (stack space)

### ✅ Use when:

* Learning the core idea.
* Not recommended for production or large inputs.

---

## 💾 Approach 2: Top-Down DP (Recursion + Memoization) 🧠

### 💡 Idea:

* Use a memoization table `dp[i][j]` to store whether the substring `s[i..j]` is a palindrome.
* Recursively check each substring, but cache results to avoid recomputation.
* Maintain variables `start` and `ans` to track the longest palindrome.

### 🔥 Advantages:

* Avoids repeated work.
* Efficient for moderately sized strings.

### 🧮 Complexity:

* Time: **O(n^2)**
* Space: **O(n^2)** (for memo table)

---

## 🧊 Approach 3: Bottom-Up DP (Tabulation) 📊

### 💡 Idea:

* Create a DP table `dp[i][j]` where `dp[i][j]` is `true` if `s[i..j]` is a palindrome.
* Fill diagonals (length 1), then length 2, then build up to length n.
* Update `start` and `ans` whenever a longer palindrome is found.

### ✅ Highlights:

* More intuitive for visual learners.
* Easy to backtrack and extract the longest substring.

### 🧮 Complexity:

* Time: **O(n^2)**
* Space: **O(n^2)**

---

## 🧪 Summary Table

| Approach       | Time Complexity | Space Complexity | Strength                     |
| -------------- | --------------- | ---------------- | ---------------------------- |
| Pure Recursion | O(2^n)          | O(n)             | Simple but inefficient       |
| Top-Down DP    | O(n^2)          | O(n^2)           | Efficient with memoization   |
| Bottom-Up DP   | O(n^2)          | O(n^2)           | Systematic and easy to trace |

---

## ✅ Final Tip:

If you need just the **length** of the LPS, or just to check **existence**, you can further optimize space. However, to return the actual substring, memoization or tabulation is ideal.

---

## ✍️ License

MIT License. Use freely with attribution.

---

**Made with ❤️ by Ridham Garg**
