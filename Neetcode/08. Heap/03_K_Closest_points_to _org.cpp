#include <vector>
#include <queue>
using namespace std;

// Approach: Use a max-heap to keep track of the k closest points to the origin.
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {

        priority_queue<vector<int>> pq;
        vector<vector<int>> ans(k);

        for (vector<int> &i : points)
        {

            // Calculate the squared distance from the origin (0, 0)
            // to avoid floating-point precision issues and avoid unnecessary square root calculation. This is withing the range of inputs.
            int dist = i[0] * i[0] + i[1] * i[1];

            // If the size of the priority queue is less than k, push the current point.
            if (pq.size() < k)
                pq.push({dist, i[0], i[1]});
            // If the size is already k, we check if the current point is closer than the farthest point in the heap.
            // If it is, we pop the farthest point and push the current point.
            else if (dist < pq.top()[0])
            {
                pq.pop();
                pq.push({dist, i[0], i[1]});
            }
        }

        // Extract the k closest points from the max-heap.
        for (int i = 0; i < k; i++)
        {
            ans[i] = {pq.top()[1], pq.top()[2]};
            pq.pop();
        }

        return ans;
    }
};

// Approach: Use sorting to find the k closest points to the origin.
class Solution {

    static bool sortFunction(vector<int>& a, vector<int>& b) {
        int A = a[0] * a[0] + a[1] * a[1];
        int B = b[0] * b[0] + b[1] * b[1];
        return A < B;
    }

public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        sort(points.begin(), points.end(), sortFunction);
        vector<vector<int>> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(points[i]);
        }
        
        return ans;
    }
};

// Approach: Use C++20's std::ranges::nth_element for a more modern and efficient solution.
#include <algorithm>
#include <ranges>

class Solution {
    // Define readable indices for x and y coordinates instead of using 0 and 1
    enum { X, Y };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Comparator lambda:
        // Compares two points based on their squared Euclidean distance from the origin (0, 0)
        // Avoids using sqrt since comparing squared distances is sufficient and faster
        auto comparator = [](const auto& a, const auto& b) {
            return a[X]*a[X] + a[Y]*a[Y] < b[X]*b[X] + b[Y]*b[Y];
        };

        // std::ranges::nth_element (C++20):
        // Rearranges the points so that the first k elements are the k smallest (closest) points
        // based on the comparator.
        // It works similarly to a partial sort but with better average-case performance: O(n)
        // The order of the first k points is not guaranteed, which is acceptable here.
        std::nth_element(points.begin(), points.begin() + k, points.end(), comparator);

        // Return the first k elements of the now partially sorted 'points' vector:
        // Constructs a new vector<vector<int>> by copying the first k elements
        // These are the k closest points to the origin
        return { points.begin(), points.begin() + k };

        /*
         So this line is shorthand for:

        return std::vector<std::vector<int>>(points.begin(), points.begin() + k);
        C++ allows this shorthand using uniform initialization ({}). The two arguments (points.begin() and points.begin() + k) are passed to the constructor of the returned object.

        { points.begin(), points.begin() + k } is not initializing a list.
        It’s calling a constructor with two arguments (iterators).

        { { points.begin(), points.begin() + k } }
        would try to call a different constructor — possibly one taking a single initializer list — which would be incorrect here.
        */
    }
};
