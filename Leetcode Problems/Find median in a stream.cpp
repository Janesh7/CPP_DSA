// 295. Find Median from Data Stream
// Hard


// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

// Example 1:

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

// Explanation
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0
 

// Constraints:

// -105 <= num <= 105
// There will be at least one element in the data structure before calling findMedian.
// At most 5 * 104 calls will be made to addNum and findMedian.
 

// Follow up:

// If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
// If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?


class MedianFinder {
public:
    double median = 0;
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;
    MedianFinder() {
        
    }

    int signum(int a,int b){
        if(a == b) return 0;
        if(a > b) return 1;
        else return -1;
    }
    
    void addNum(int num) {
        switch(signum(maxi.size(),mini.size())){
            // ODD
            // If the two heaps are the same size, push the element to the min-heap if it is greater than the median,
            // or to the max-heap if it is less than the median.
            case 0:
                if(num > median){
                    mini.push(num);
                    median = mini.top();
                }
                else{
                    maxi.push(num);
                    median = maxi.top();
                }
                break;
            case 1:
            // If the max-heap is larger than the min-heap, push the element to the min-heap if it is greater than the median,
            // or to the max-heap and pop the top element from the max-heap and push it to the min-heap if it is less than the median.
                if(num > median){
                    mini.push(num);
                    median = (mini.top() + maxi.top())/2.0;
                }
                else{
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(num);
                    median = (mini.top() + maxi.top())/2.0;
                }
                break;
            case -1:
            // If the min-heap is larger than the max-heap, push the element to the max-heap if it is greater than the median,
            // or to the min-heap and pop the top element from the min-heap and push it to the max-heap if it is less than the median.
                if(num > median){
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(num);
                    median = (mini.top() + maxi.top())/2.0;
                }
                else{
                    maxi.push(num);
                    median = (mini.top() + maxi.top())/2.0;
                }
                break;
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */