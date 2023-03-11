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