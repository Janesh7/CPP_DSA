// You are given two arrays of strings that represent two inclusive events that happened on the same day, event1 and event2, where:

// event1 = [startTime1, endTime1] and
// event2 = [startTime2, endTime2].
// Event times are valid 24 hours format in the form of HH:MM.

// A conflict happens when two events have some non-empty intersection (i.e., some moment is common to both events).

// Return true if there is a conflict between two events. Otherwise, return false.



// Approach

// The function compares the start and end times of the two events using string comparison. The start time of event1 is accessed using event1[0], and the end time of event1 is accessed using event1[1]. Similarly, the start time of event2 is accessed using event2[0], and the end time of event2 is accessed using event2[1].

// The condition event1[1] >= event2[0] checks if the end time of event1 is greater than or equal to the start time of event2. This condition ensures that there is some overlap or intersection between the two events.

// The condition event1[0] <= event2[1] checks if the start time of event1 is less than or equal to the end time of event2. This condition also ensures that there is some overlap or intersection between the two events.

// If both conditions are true, it means that there is a non-empty intersection between the two events, indicating a conflict. In this case, the function returns true. Otherwise, if any of the conditions is false, it means there is no conflict, and the function returns false


class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return event1[1] >= event2[0] && event1[0] <= event2[1];
    }
};