# Generate Parentheses: Time Complexity & Approach Details

## Problem Overview

Given `n` pairs of parentheses, the task is to generate all combinations of well-formed parentheses. A well-formed parentheses string means:
- Every opening parenthesis `(` has a corresponding closing parenthesis `)`.
- No closing parenthesis `)` appears before a matching opening parenthesis `(`.

For example, when `n = 3`, valid combinations include:
```
["((()))", "(()())", "(())()", "()(())", "()()()"]
```

### Brute Force Solution and its Time Complexity

The brute force approach involves generating all possible combinations of parentheses and checking whether each combination is valid. For every string, the function `valid()` checks whether the parentheses are balanced (i.e., each `(` is matched by a `)`).

While this approach is correct, it's inefficient, especially for larger values of `n` because it generates all possible strings of length `2n`, which is `2^(2n)` possible combinations. This results in a time complexity of `O(2^(2n) * n)`.

### Why Catalan Numbers?

The key observation is that the number of valid parentheses combinations is related to **Catalan numbers**, which is a sequence of numbers that appear in various counting problems, including the number of valid combinations of parentheses.

#### What are Catalan Numbers?

The **n-th Catalan number**, `C_n`, can be represented by the formula:

\[
C_n = \frac{(2n)!}{(n+1)!n!}
\]

It can also be defined recursively as:

\[
C_0 = 1
\]
\[
C_n = \sum_{i=0}^{n-1} C_i \cdot C_{n-1-i} \quad \text{for} \quad n > 0
\]

For instance:
- `C_0 = 1` (there is exactly one way to form valid parentheses with zero pairs: the empty string).
- `C_1 = 1` (there is exactly one valid string with one pair: `()`).
- `C_2 = 2` (the two valid strings are: `()()` and `(())`).
- `C_3 = 5` (the five valid strings are: `((()))`, `(()())`, `(())()`, `()(())`, and `()()()`).

### How Does the Catalan Number Relate to Time Complexity?

#### Backtracking Approach:

In the backtracking approach, we are recursively trying to build a valid parentheses string by adding either an opening parenthesis `(` or a closing parenthesis `)` at each step. The valid combinations of parentheses are limited by the fact that the number of opening parentheses cannot exceed `n` and the number of closing parentheses cannot exceed the number of opening parentheses at any point.

The valid sequences of parentheses correspond directly to **Catalan numbers**. For each valid sequence of parentheses, there is exactly one valid arrangement of `n` pairs of parentheses.

Thus, the number of valid combinations grows exponentially, but it is bounded by the **n-th Catalan number**, rather than the total number of permutations of parentheses (which is `2^(2n)`). This results in the time complexity of the backtracking approach being `O(C_n * n)`, where `C_n` is the n-th Catalan number, because for each valid sequence, we perform some constant amount of work (appending characters).

#### Dynamic Programming (DP) Approach:

The DP approach avoids redundant computation by storing results for smaller subproblems, which makes it more efficient than the brute force approach.

### DP Approach Detailed Explanation

#### General DP Idea:

We define `res[k]` as the list of all valid parentheses combinations that can be formed with `k` pairs of parentheses. Initially, `res[0] = {""}` because with zero pairs, the only valid combination is the empty string.

We then build up from `res[1]` to `res[n]` using the following rule:

For each `k`, we combine valid parentheses strings from `res[i]` (where `i` is less than `k`) and `res[k - i - 1]` (the complement of the remaining parentheses). The idea is to form all valid combinations by wrapping the valid combinations from `res[i]` in parentheses and appending valid combinations from `res[k - i - 1]`.

#### Key Line of Code:

```cpp
res[k].push_back("(" + left + ")" + right);
```

Let's break this down step by step.

1. **Combining `left` and `right`**: 
    - `left` comes from `res[i]`, representing valid parentheses combinations with `i` pairs of parentheses.
    - `right` comes from `res[k - i - 1]`, representing valid parentheses combinations with `k - i - 1` pairs of parentheses.

2. **Why wrap `left` in `()` and then append `right`?**:
    - The reason we wrap `left` with `(` and `)` is that the string `left` represents a valid sequence of parentheses, so placing it inside another pair of parentheses ensures that it remains valid. After wrapping `left`, we concatenate it with `right`, which is a valid sequence for the remaining `k - i - 1` pairs.
    - The other combinations such as `right + left` or `() + left + right` would not maintain the balance between opening and closing parentheses, leading to invalid combinations. For example, `(left + right)` might be valid for `left`, but putting `right` before `left` would break the rule of balanced parentheses.

3. **How this works in the loop**:
    - We loop through each `i` from 0 to `k - 1` (i.e., trying different splits of `k` pairs of parentheses).
    - For each split, we generate the valid combination by wrapping the sequence from `res[i]` with `()` and concatenating it with sequences from `res[k - i - 1]`.

#### Time Complexity of DP Approach:

The total number of valid parentheses combinations for `n` pairs is the **n-th Catalan number**, `C_n`. For each `k` (where `k` is the number of pairs), we generate combinations by combining the results from `res[i]` and `res[k-i-1]`. This is a recursive process that involves iterating over all possible splits, and since the total number of splits is proportional to `C_n`, the overall time complexity is `O(C_n * n)`.

Thus, the time complexity is directly related to the growth of Catalan numbers.

#### Space Complexity:

The space complexity is `O(C_n)` because we are storing all valid combinations for each `k` in `res[k]`. Since the total number of valid combinations is the n-th Catalan number, the space complexity is proportional to `C_n`.

---
