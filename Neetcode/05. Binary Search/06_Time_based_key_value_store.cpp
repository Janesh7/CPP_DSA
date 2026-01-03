// 981. Time Based Key-Value Store
// Solved
// Medium
// Topics
// Companies
// Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

// Implement the TimeMap class:

// TimeMap() Initializes the object of the data structure.
// void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
// String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
 

// Example 1:

// Input
// ["TimeMap", "set", "get", "get", "set", "get", "get"]
// [[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
// Output
// [null, null, "bar", "bar", null, "bar2", "bar2"]

// Explanation
// TimeMap timeMap = new TimeMap();
// timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
// timeMap.get("foo", 1);         // return "bar"
// timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
// timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
// timeMap.get("foo", 4);         // return "bar2"
// timeMap.get("foo", 5);         // return "bar2"
 

// Constraints:

// 1 <= key.length, value.length <= 100
// key and value consist of lowercase English letters and digits.
// 1 <= timestamp <= 107
// All the timestamps timestamp of set are strictly increasing.
// At most 2 * 105 calls will be made to set and get.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <map>
using namespace std;

class TimeMap {
public:
    
    unordered_map<string, map<int,string>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        if (it == m[key].begin())
            return "";
        it--;
        return it->second;
    }
};

class TimeMap {
public:
    
    // 'm' is an unordered_map where each key corresponds to a map.
    // The key is a string, and the map stores pairs of timestamp (int) and associated value (string).
    // The map is sorted by timestamp automatically, so we can efficiently query the largest timestamp <= given timestamp.
    unordered_map<string, map<int, string>> m;

    // Constructor initializes the TimeMap object.
    TimeMap() {
        // No explicit initialization needed for the unordered_map as it is automatically handled.
    }

    // 'set' function stores the value for a given key at a specific timestamp.
    void set(string key, string value, int timestamp) {
        // For the given key, store the timestamp-value pair in the map.
        // The 'map' automatically keeps the timestamps sorted.
        m[key][timestamp] = value;
    }
    
    // 'get' function retrieves the value for the given key at the largest timestamp <= the given timestamp.
    string get(string key, int timestamp) {
        // Step 1: Try to find the first timestamp that is strictly greater than the given 'timestamp'.
        auto it = m[key].upper_bound(timestamp);
        
        // Step 2: Check if the iterator is at the beginning of the map.
        // If it is, it means there is no timestamp <= the requested 'timestamp'.
        if (it == m[key].begin()) {
            // If no such timestamp exists, return an empty string.
            return "";
        }
        
        // The upper_bound function gives us the first element that is greater than the timestamp.

        // To find the largest element less than or equal to timestamp, we need to move the iterator one step back to the previous element, which holds the largest valid timestamp for the query.

        // Example Walkthrough:
        
        // Step 3: Move the iterator one step back to point to the largest timestamp <= 'timestamp'.
        it--;
        
        // Step 4: Return the value associated with that largest timestamp <= 'timestamp'.
        return it->second;
    }
};
