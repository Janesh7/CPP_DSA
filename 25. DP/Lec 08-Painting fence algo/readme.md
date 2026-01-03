**VVIMP Painting Fence Algorithm**

**Recursive Relation**

The painting fence algorithm can be solved using a recursive relation. The basic idea is to consider the two cases:

1. The last two posts are painted the same color. In this case, we can only paint the current post with a different color.
2. The last two posts are painted different colors. In this case, we can paint the current post with any of the k colors.


Let's define the following sets:

* S: The set of all ways to paint a fence with n posts and k colors such that no more than two adjacent posts have the same color.
* R: The subset of S where the last two posts are painted the same color.
* D: The subset of S where the last two posts are painted different colors.

We know that the total number of ways to paint the fence is S = R + D.

Let's define the following function:

```cpp
int countDerangementsNaive(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    return (k - 1) * (countDerangementsNaive(n - 1) + countDerangementsNaive(n - 2));
}
```

**EASY TO UNDERSTAND WITH EX**

**Examples**

Here are some examples of how to use the recursive relation to solve the painting fence problem:

**Example 1:**

```
n = 2 , 2 blocks
k = 3 , 3 colours R,G,B
```

We can have the following two cases:

* Both posts are painted the same color: RR, GG, or BB. [3]
* Both posts are painted different colors: RG, GB, RB, GR, BG or BR. [6]

**Total=3+6=9**

**Example 2:**

```
n = 3, 3 blocks
k = 3
```

We can have the following cases:

* All three posts are painted the same color: **Take the 6 different colour from prev and then add the same colour as the last to make it same** ex RG-> RGG, GB->GBB, RBB, GRR, BGG or BRR. [6].. -> same[i] = different[i-1]
* Two posts are painted the same color and the other post is painted a different color: **we have total 9 combos in prev .. what we need to have is different coulour as last.. so for that there can be 9*(k-1) .. explanation w Ex. we have RR,GG,BB,RG,GB,RB,GR,BG,BR from prev step.. so for RR, to have different colour we can have any colour except R, ie(G,B) ie K-1=(3-1)=2 same is the case for all the 9 cases .. so it becomes 9*2=18**  [18] .. -> diff[i]=total[i-1]x(k-1)

**Total=6+18=24**

**HENCE WE GET THE RELATION**
- `same[i] = diff[i-1]`
- `diff[i] = total[i-1] * (k-1)`

Now to understand the recursive relations

- `SAME`: n=4 to get the **same colour part.. we know at max 2 colours can come continous.. so we need n-2 sub problem answer as the last two block is same.. in our case they are RR,GG,BB .. so to get the same colour we need the sub problem answer for n-2(IMP: 2 r saved for our last block RR,GG,BB).. here 4-2=2 .. the different cases were RG,GB,RB,GR,BG,BR (also RR,GG,BB ,but NOT SURE) .. so lets take RG, we can have any 2 similar block except GG pair .. ie RR,GG ie k-1=2, -> RGRR,RGGG  .. same for other pairs .. so it gives the relation rec(n-2)*(k-1)**

- `DIFFERENT`: n=4, **we just need to place the last element different.. so we need n-1 sub problem answer .. from n=3 we get RGB,RGG,RBG,RBB,BRG and so on we should have the last element different so like RGB can have R,G but not B.. so this is (k-1)=2 .. same for all other pairs.. so the equation becomes rec(n-1)*(k-1)**

SEE CODE FOR EASY

# Painting Fence Algorithm

## Problem Description

Given a fence with `n` posts and `k` colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color. Since the answer can be large, return it modulo 10^9 + 7.

### Examples:

- Input: `n = 2, k = 4`
  Output: 16
  Explanation: We have 4 colors and 2 posts.
  - Ways when both posts have the same color: 4
  - Ways when both posts have different colors: 4 (choices for 1st post) * 3 (choices for 2nd post) = 12

- Input: `n = 3, k = 2`
  Output: 6

  
SO:

- `diff` = number of ways when the color of the last two posts is different.
- `same` = number of ways when the color of the last two posts is the same.
- `total ways` = `diff + same`

For `n = 1`:
- `diff` = `k`
- `same` = 0
- `total` = `k`

For `n = 2`:
- `diff` = `k * (k - 1)` (k choices for the first post, k-1 for the next)
- `same` = `k` (choices for the common color of two posts)
- `total` = `k + k * (k - 1)`

For `n = 3`:
- `diff` = (previous total ways) * `(k - 1)`
- `same` = previous `diff` ways * `k * (k-1)`

Hence we deduce that:
- `total[i] = same[i] + diff[i]`
- `same[i] = diff[i-1]`
- `diff[i] = total[i-1] * (k-1)`

### Implementation

```cpp
// C++ program for Painting Fence Algorithm
// (optimised version)

#include <bits/stdc++.h>
using namespace std;

// Returns count of ways to color k posts
long countWays(int n, int k)
{
    long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    long long mod = 1000000007;

    dp[1] = k;
    dp[2] = k * k;

    for (int i = 3; i <= n; i++) {
        dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
    }

    return dp[n];
}

// Driver code
int main()
{
    int n = 3, k = 2;
    cout << countWays(n, k) << endl;
    return 0;
}
```

#### Output:
```
6
```

### Time Complexity: O(N)
### Auxiliary Space: O(N)

### Space Optimization

We can optimize the above solution to use one variable instead of a table.

```cpp
// C++ program for Painting Fence Algorithm

#include <bits/stdc++.h>
using namespace std;

// Returns count of ways to color k posts using k colors
long countWays(int n, int k)
{
    // There are k ways to color the first post
    long total = k;
    int mod = 1000000007;

    // There are 0 ways for a single post to violate (same color) and k ways to not violate (different color)
    int same = 0, diff = k;

    // Fill for 2 posts onwards
    for (int i = 2; i <= n; i++) {
        // Current same is the same as the previous diff
        same = diff;

        // We always have k-1 choices for the next post
        diff = total * (k - 1);
        diff = diff % mod;

        // Total choices until i.
        total = (same + diff) % mod;
    }

    return total;
}

// Driver code
int main()
{
    int n = 3, k = 2;
    cout << countWays(n, k) << endl;
    return 0;
}
```

#### Output:
```
6
```

### Time Complexity: O(N)
### Auxiliary Space: O(1)

---

Feel free to replace `n` and `k` in the code examples with your specific input values to compute the desired results.