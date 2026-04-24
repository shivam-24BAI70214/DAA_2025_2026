## Algorithm(Dynamic Programming)

1. Let `m = s.length()` and `n = t.length()`
2. Create a 2D array `dp[m+1][n+1]`
3. Initialize base case:
   - Set `dp[i][0] = 1` for all `i` (empty `t` can always be formed)
   - Set `dp[0][j] = 0` for all `j > 0` (non-empty `t` cannot be formed from empty `s`)
4. Iterate through the strings:
   - For `i` from `1` to `m`:
     - For `j` from `1` to `n`:
       - If `s[i-1] == t[j-1]`:
         - `dp[i][j] = dp[i-1][j-1] + dp[i-1][j]`
       - Else:
         - `dp[i][j] = dp[i-1][j]`
5. Return `dp[m][n]` as the final answer

---

## ⏱️ Time Complexity
- **O(m × n)**  
  We fill a DP table of size `(m+1) × (n+1)`

---

## 🧠 Space Complexity
- **O(m × n)**  
  Due to the 2D DP table used for computation
