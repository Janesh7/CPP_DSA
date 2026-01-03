long long minCost(long long arr[], long long n) {
    // Create a min-heap (priority queue) to store rope lengths.
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    // Add all the rope lengths to the priority queue.
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }
    
    long long ans = 0;
    
    // Continue until there is only one rope left in the priority queue.
    while (pq.size() > 1) {
        // Extract the two smallest rope lengths.
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        
        // Calculate the sum of these two lengths.
        long long sum = first + second;
        
        // Add the sum to the answer (total cost).
        ans += sum;
        
        // Push the sum (new rope) back into the priority queue.
        pq.push(sum);
    }
    
    // Return the minimum cost (the answer).
    return ans;
}
