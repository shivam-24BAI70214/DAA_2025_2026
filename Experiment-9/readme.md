# Minimum Sum Partition (Based on Java Code)

## Algorithm

1. Initialize total sum
   - Set `totSum = 0`
   - Traverse array and add all elements to get total sum

2. Create DP array
   - Create a boolean array `dp` of size `totSum + 1`
   - `dp[i]` means: subset with sum `i` is possible

3. Base case
   - Set `dp[0] = true` (sum 0 is always possible)

4. Fill DP array
   - For each element `num` in array:
     - Traverse `j` from `totSum` down to `num`
     - Update:
       dp[j] = dp[j] OR dp[j - num]

5. Find minimum difference
   - Initialize `minDif = infinity`
   - Traverse `j` from `0` to `totSum / 2`
   - If `dp[j] == true`:
       minDif = min(minDif, totSum - 2*j)

6. Return result
   - Return `minDif`

---

## Time Complexity (TC)

O(n * totSum)

- `n` = number of elements  
- `totSum` = sum of all elements  

---

## Space Complexity (SC)

O(totSum)

- Using one DP array of size `totSum + 1`
