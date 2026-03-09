To master LeetCode, you don't need to memorize 4,000 different solutions. Instead, you need to recognize the **fundamental patterns** that underlying almost all of them. Software engineers have categorized these into roughly 15-20 core algorithmic patterns. 

Here is the ultimate, exhaustive guide to **spotting the pattern** based on the problem description, constraints, and keywords.

---

### 1. The "Array / String" Patterns

These are the most common patterns you will encounter. They rely heavily on how you iterate through contiguous data.

#### Pattern 1: Sliding Window
*   **The Vibe:** You are looking at a contiguous subset of elements within a larger array or string.
*   **Keywords:** "Contiguous", "Subarray", "Substring", "Longest", "Shortest", "Maximum/Minimum size", "Contains exactly K".
*   **The Strategy:** Maintain a window with `left` and `right` pointers. Expand `right` to satisfy a condition. Shrink `left` when the condition is broken until it's satisfied again. Keep track of the target metric (max length, min length, etc.) during this expansion/shrinking phase.
*   **Classic Problems:** Longest Substring Without Repeating Characters, Minimum Size Subarray Sum.

#### Pattern 2: Two Pointers
*   **The Vibe:** You need to pair elements up, or you need to process an array from both ends simultaneously.
*   **Keywords:** "Sorted array", "Pair", "Sum of two/three elements", "Palindrome", "Reverse", "In-place".
*   **The Strategy:** Place one pointer at the start `left = 0` and one at the end `right = len(arr) - 1`. Move them towards each other based on a condition (e.g., if their sum is too small, move `left` right; if too big, move `right` left).
*   **Classic Problems:** Two Sum II, 3Sum, Container With Most Water, Valid Palindrome.

#### Pattern 3: Fast & Slow Pointers (Tortoise & Hare)
*   **The Vibe:** You need to find a cycle, a middle element, or a specific structural property in a sequence (usually applied to Linked Lists or Arrays where values point to indices).
*   **Keywords:** "Cycle", "Middle", "Duplicate", "Linked List", "Determine if it loops".
*   **The Strategy:** Move a `slow` pointer one step at a time, and a `fast` pointer two steps at a time. If there's a cycle, they will eventually meet. If `fast` reaches the end, there is no cycle (or the middle is where `slow` currently is).
*   **Classic Problems:** Linked List Cycle, Find the Duplicate Number, Happy Number.

#### Pattern 4: Merge Intervals
*   **The Vibe:** You are given lists of start and end times, sets of ranges, or overlapping periods.
*   **Keywords:** "Intervals", "Overlapping", "Merge", "Insert", "Scheduling", "Meeting rooms".
*   **The Strategy:** Sort the intervals primarily by their *start times*. Then, iterate through them, maintaining the "current active interval." If the next interval overlaps (its start time is less than or equal to the current's end time), update the current interval's end time. Otherwise, add the current to the result and start tracking the next one.
*   **Classic Problems:** Merge Intervals, Insert Interval, Meeting Rooms II.

#### Pattern 5: Cyclic Sort
*   **The Vibe:** You are dealing with an array of numbers in a strictly bounded range, usually `1 to N` or `0 to N`.
*   **Keywords:** "Array of size N", "Numbers from 1 to N", "Missing number", "Duplicate number", "Smallest positive missing".
*   **The Strategy:** Iterate through the array. For every number `x`, its correct index in a sorted array is `x - 1` (or `x` if 0-indexed). If a number is not at its correct index, swap it with the number that currently occupies that index. Repeat until the current index holds the correct number or is out of bounds/duplicate.
*   **Classic Problems:** Missing Number, Find All Duplicates in an Array, First Missing Positive.

---

### 2. The "Prefix State" Patterns

When you need to know about everything that happened *before* the current element.

#### Pattern 6: Prefix Sum / Prefix Hash 
*   **The Vibe:** You need to calculate the sum, product, or a specific property of contiguous subarrays *rapidly*, often multiple times or while iterating.
*   **Keywords:** "Subarray sum equals K", "Contiguous array", "Divisible by K".
*   **The Strategy:** Keep a running total (or running XOR, etc.) as you iterate. Keep a Hash Map where keys are the running totals and values are frequencies (or indices). If `current_running_total - target` exists in the Hash Map, you have found a valid subarray ending at your current position.
*   **Classic Problems:** Subarray Sum Equals K, Contiguous Array, Continuous Subarray Sum.

#### Pattern 7: Monotonic Stack
*   **The Vibe:** You need to find the "next greater" or "next smaller" element for every item in an array.
*   **Keywords:** "Next greater element", "Next smaller element", "Daily temperatures", "Histogram", "Stock span".
*   **The Strategy:** Use a Stack to keep track of elements (usually their indices). The stack is strictly increasing (or decreasing). When you hit an element that breaks the monotonic rule, you pop from the stack—and the element you just hit is the "next greater/smaller" for the elements you are popping!
*   **Classic Problems:** Daily Temperatures, Largest Rectangle in Histogram, Trapping Rain Water.

---

### 3. The "Tree / Graph / Matrix" Patterns

Traversing hierarchical or networked structures.

#### Pattern 8: Tree/Graph Breadth-First Search (BFS)
*   **The Vibe:** You need to explore a structure level-by-level, or you need to find the *shortest path* in an unweighted graph/grid.
*   **Keywords:** "Level order", "Shortest path", "Minimum steps", "Closest", "Word ladder", "Matrix paths".
*   **The Strategy:** Use a Queue. Enqueue the starting node(s). While the queue is not empty, process the current node, then enqueue all its valid unvisited neighbors. Use a `visited` set to avoid cycles. To track levels/distance, process the queue in batches (`for _ in range(len(queue))`).
*   **Classic Problems:** Binary Tree Level Order Traversal, Rotting Oranges, Shortest Path in Binary Matrix, Word Ladder.

#### Pattern 9: Tree/Graph Depth-First Search (DFS)
*   **The Vibe:** You need to explore all possible paths to the end, find connected components, or exhaustively search combinations. 
*   **Keywords:** "Path sum", "All paths", "Connected components", "Number of islands", "Reach the end".
*   **The Strategy:** Use recursion (implicitly using the call stack) or an explicit Stack. Go as deep as possible down one path before backtracking to explore others. Mark nodes as visited.
*   **Classic Problems:** Number of Islands, Max Area of Island, Lowest Common Ancestor.

#### Pattern 10: Topological Sort
*   **The Vibe:** You have a set of tasks with prerequisites. You need to find a valid order to complete them. The graph is Directed and Acyclic (DAG).
*   **Keywords:** "Prerequisites", "Dependencies", "Course schedule", "Build order", "Valid ordering".
*   **The Strategy (Kahn's Algorithm):** Compute the "in-degree" (number of incoming edges) for every node. Push all nodes with in-degree `0` to a Queue. While the Queue has nodes, pop one, add it to your sorted order, and decrement the in-degree of all its neighbors. If a neighbor's in-degree drops to `0`, push it to the Queue. If the output length doesn't match total nodes, there's a cycle.
*   **Classic Problems:** Course Schedule I & II, Alien Dictionary.

#### Pattern 11: Union Find (Disjoint Set)
*   **The Vibe:** You need to dynamically group elements together, check if two elements belong to the same group, or count the number of disjoint groups.
*   **Keywords:** "Connected components", "Dynamic connectivity", "Redundant connection", "Group", "Network".
*   **The Strategy:** Create an array where `parent[i] = i`. Create a `find(i)` function that traces the parent hierarchy up to the root (using path compression). Create a `union(i, j)` function that attached the root of `i` to the root of `j` (using union by rank/size).
*   **Classic Problems:** Redundant Connection, Number of Connected Components in an Undirected Graph, Accounts Merge.

---

### 4. The "Search & Sort" Patterns

#### Pattern 12: Modified Binary Search
*   **The Vibe:** You are given an array that is sorted, partially sorted, or rotated, and you need to find an element or a specific condition in $O(\log N)$ time. *Or*, you are looking for an answer in a monotonic range (e.g., minimum capacity, maximum distance).
*   **Keywords:** "Sorted array", "Rotated array", "Find in $O(\log N)$", "Minimum capacity to ship", "Maximum minimum distance".
*   **The Strategy:** Standard Binary Search on indices (`left`, `right`, `mid`). **OR** Binary Search on the *Answer Space*: Define a search space `[min_possible_answer, max_possible_answer]`. Write a helper function `is_valid(mid)` to check if a proposed answer `mid` works. Discard half the space based on the result.
*   **Classic Problems:** Search in Rotated Sorted Array, Find Minimum in Rotated Sorted Array, Koko Eating Bananas, Capacity To Ship Packages Within D Days.

#### Pattern 13: Top K Elements (Heaps)
*   **The Vibe:** You need to find the $K$-th largest, $K$-th smallest, or the top $K$ most frequent elements in a dataset.
*   **Keywords:** "Top K", "K-th largest/smallest", "K most frequent", "Closest K".
*   **The Strategy:** Use a Heap (Priority Queue).
    *   For "Top K Largest", maintain a **Min-Heap** of size $K$. When adding, if the heap exceeds size $K$, pop the smallest. You are left with the $K$ largest.
    *   For "Top K Smallest", maintain a **Max-Heap** of size $K$.
*   **Classic Problems:** Kth Largest Element in an Array, Top K Frequent Elements, Find K Closest Elements.

#### Pattern 14: Two Heaps
*   **The Vibe:** You need to dynamically find the median of a stream of numbers.
*   **Keywords:** "Median", "Data stream", "Sliding window median".
*   **The Strategy:** Maintain a Max-Heap for the left half of the numbers (the smaller numbers) and a Min-Heap for the right half (the larger numbers). Ensure the sizes differ by at most 1. The median is either the root of the larger heap or the average of both roots.
*   **Classic Problems:** Find Median from Data Stream, Sliding Window Median.

---

### 5. The "Combinatorics & Optimization" Patterns

#### Pattern 15: Backtracking (Subsets/Permutations)
*   **The Vibe:** You need to generate all possible combinations, permutations, or subsets. The answer requires exploring all valid paths.
*   **Keywords:** "Generate all", "Combinations", "Permutations", "Subsets", "Sudoku", "N-Queens".
*   **The Strategy:** Build candidates step-by-step using recursion. 
    1. Check if the current state is a valid solution. If so, add it.
    2. Iterate through available choices.
    3. Make a choice (e.g., add to a temporary path array).
    4. Recurse.
    5. **Backtrack:** Undo the choice (e.g., pop from the path array) so you can try the next option.
*   **Classic Problems:** Subsets, Permutations, Combination Sum, Word Search.

#### Pattern 16: Dynamic Programming (DP) - 1D and 2D
*   **The Vibe:** You are asked to find the max/min of something, the total number of ways to do something, or if something is possible. The problem can be broken down into identical overlapping subproblems.
*   **Keywords:** "Maximum profit", "Minimum cost", "Number of ways", "Longest common subsequence", "Knapsack".
*   **The Strategy:**
    *   **State:** What variables determine the current subproblem? (e.g., index `i`, remaining capacity `w`).
    *   **Base Case:** What is the answer for the smallest subproblem?
    *   **Transitions:** How does state $N$ relate to state $N-1$ (and $N-2$, etc.)? Create a recurrence relation.
    *   **Implementation:** Use Top-Down (Recursion + Memoization) or Bottom-Up (Tabulation).
*   **Classic DP Sub-Patterns:**
    *   *Fibonacci sequence:* Climbing Stairs, House Robber.
    *   *0/1 Knapsack:* Partition Equal Subset Sum, Target Sum.
    *   *Longest Common Subsequence:* Edit Distance, Interleaving String.
    *   *Palindromes:* Longest Palindromic Substring.

#### Pattern 17: Trie (Prefix Tree)
*   **The Vibe:** You are dealing with dictionaries of words, matching prefixes, or auto-complete functionality.
*   **Keywords:** "Words dictionary", "Prefix", "Search word", "Start with", "Auto-complete".
*   **The Strategy:** Build a tree where each node represents a character. Paths down the tree represent words. Mark the end of a valid word with a boolean flag at that node.
*   **Classic Problems:** Implement Trie (Prefix Tree), Word Dictionary, Word Search II.

