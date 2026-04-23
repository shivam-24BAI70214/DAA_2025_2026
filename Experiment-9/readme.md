# Minimum Sum Partition

## Algorithm

1. Find total sum of array
   S = sum(arr)

2. Create a boolean array dp of size S + 1
   dp[i] means: can we make sum i using elements

3. Initialize
   dp[0] = true
   rest all = false

4. Fill dp array
   for each element num in arr:
       for j from S down to num:
           if dp[j - num] is true:
               dp[j] = true

5. Find answer
   minDiff = infinity

   for j from 0 to S/2:
       if dp[j] is true:
           minDiff = min(minDiff, S - 2*j)

6. Return minDiff

---

## Time Complexity (TC)
O(n * S)

n = number of elements  
S = total sum of array

---

## Space Complexity (SC)
O(S)

(we use one dp array)
