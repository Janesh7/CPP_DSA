
// Allocate Books
// Medium

// Problem Statement
// Given an array ‘arr’ of integer numbers . where ‘arr[i]’ represents the number of pages in the ‘i-th’ book. There are ‘m’ number of students and the task is to allocate all the books to their students. Allocate books in such a way that:
// 1. Each student gets at least one book.
// 2. Each book should be allocated to a student.
// 3. Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
// Example:
// Let’s consider ‘n=4’ (number of books ) and ‘m=2’ (number of students).
// ‘arr = { 10, 20, 30, 40 }’.
// subsequence

// All possible way to allocate the ‘4’ books in ‘2’ number of students is -
// 10 | 20, 30, 40 - sum of all the pages of books which allocated to student-1 is ‘10’, and student-2 is ‘20+ 30+ 40 = 90’ so maximum is ‘max(10, 90)= 90’.
// 10, 20 | 30, 40 - sum of all the pages of books which allocated to student-1 is ‘10+ 20 = 30’, and student-2 is ‘30+ 40 = 70’ so maximum is ‘max(30, 70)= 70’.
// 10, 20, 30 | 40 - sum of all the pages of books which allocated to student-1 is ‘10+ 20 +30 = 60’, and student-2 is ‘40’ so maximum is ‘max(60, 40)= 60’.
// So possible maximum number of pages which allocated to a single student is { 90, 70, 60 }.
// But you have to return a minimum of this so return ‘min(90,70,60) =60’.
// Note:
// 1. Do not print anything, just return the maximum number of pages that are assigned to a student is minimum.
// 2. If it is not possible to assign the ‘n’ books to ‘m’ students then return ‘-1’.
// Detailed explanation ( Input/output format, Notes, Constraints, Images )

// Sample Input 1:
// 4 2
// 12 34 67 90
// Sample Output 1:
// 113
// Explanation Of Sample Input 1:
// Let’s consider ‘n=4’ (number of books ) and ‘m=2’ (number of students)
// ‘arr = { 12, 34, 67, 90 }’. And ‘m= 2’.
// All possible way to allocate the ‘4’ books in ‘2’ number of students is-

// 12 | 34, 67, 90 - sum of all the pages of books which allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’ so maximum is ‘max(12, 191)= 191’.
// 12, 34 | 67, 90 - sum of all the pages of books which allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’ so maximum is ‘max(46, 157)= 157’.
// 12, 34, 67 | 90 - sum of all the pages of books which allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’ so maximum is ‘max(113, 90)= 113’.

// So possible maximum number of pages which allocated to a single student is { 191, 157, 113 } 
// But you have to return a minimum of this so return ‘min(191,157, 113) =113’.

// Hence answer is ‘113’.

#include<vector>
using namespace std;
// function to checjk if the two student book allocation is possible 
bool isPossible(vector<int> arr, int n, int m, int mid) {
    // m is the number of student ie 2 in our examples studied
    int studentCount = 1; // start with the 1st student
    int pageSum = 0;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {  // condition that see if adding another book is possible or no
            pageSum += arr[i];
        }
        else
        {
            studentCount++;  // above condition fails hence add another student 
            if(studentCount > m || arr[i] > mid ) { // if the number of student increases than the required return false
            //  if the next number is greater than the mid value we know above equation are going to fail always and its not possible to allocate books anymore, hence return false for that case as well
                return false;
        }
        // means number of students are there to allocate and it is possible to allocate the books
            pageSum = arr[i];
            // This step is as good as pageSum = 0; pageSum += arr[i]; as the i book with arr[i] pages werent included for the previous student and hence the next valid student gets it. And then the loop continues for that student 
        }
        if(studentCount > m) {
            return false;
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int s = 0;
    int sum = 0;
    //  We know that the value will always lie between 0 to the (at max) sum of all values 
    //  hence we can apply b search to find it
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum; // take start as 0 and end as sum
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            ans = mid; // if its possible store the answer and carry on with the checking till s>e
            e = mid - 1; // if it is possibile for mid value it is also valid for any value greater than mid and we want to neglect all those as we want the min value 
        }
        else
        {
            s = mid + 1; // not valid for mid hence(we have to increase the mid value in order to find valid values) make start to mid + 1 and check
        }
        mid = s + (e-s)/2;
    }
    return ans;
}