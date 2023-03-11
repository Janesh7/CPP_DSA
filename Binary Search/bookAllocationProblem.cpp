#include<vector>
using namespace std;
// function to checjk if the two student book allocation is possible 
bool isPossible(vector<int> arr, int n, int m, int mid) {
    // m is the number of student ie 2 in our case
    int studentCount = 1; // start with the 1st student
    int pageSum = 0;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {  // condition that see if adding another book is possible or no
            pageSum += arr[i];
        }
        else
        {
            studentCount++;  // above condition fails hence add another student 
            if(studentCount > m || arr[i] > mid ) { // if the number of student increases than the required
            return false;
        }
            pageSum = arr[i];
        }
        if(studentCount > m) {
            return false;
        }
        //cout << " for i " << i << " Student "<< studentCount << " pageSum " << pageSum << endl;
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int s = 0;
    int sum = 0;
    
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            //cout<<" Mid returned TRUE" << endl;
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}