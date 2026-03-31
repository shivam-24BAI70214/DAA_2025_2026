# Algorithm
---
1. Create a graph using a HashMap where each key represents a city
   and stores a list of (neighbor, price).

2. Traverse the flights array and build the adjacency list.

3. Initialize a priority queue (min-heap) to store:
   (cost, current node, number of stops).

4. Insert the source node into the priority queue with:
   cost = 0 and stops = 0.

5. Create a HashMap (dist) to store the minimum cost for
   each (node, stops) combination.

6. While the priority queue is not empty:
   a. Remove the element with the smallest cost.
   b. Extract cost, current node, and stops.

   c. If current node equals destination:
      return the cost.

   d. If stops exceed k:
      skip this iteration.

   e. If current node has no neighbors:
      continue.

   f. For each neighbor of the current node:
      i. Calculate newCost = current cost + price.
      ii. Create a key using (neighbor, stops).
      iii. If this path is cheaper than previous:
           update dist map.
           push (newCost, neighbor, stops + 1) into queue.

7. If destination is not reached, return -1.
