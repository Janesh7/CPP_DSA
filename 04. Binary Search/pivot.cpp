#include<iostream> 
using namespace std;

int getPivot(int arr[], int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])  //Used to narrow the search space from start.. 
        // This cond rep that mid is in first line therefore increment the start
        // we r using arr[0] as we know that it is the least value in the incrementing upslope and the fact that the pivot value will always lie bellow that 0th element
        // check binary notes 2
        {
            s = mid+1;
        }
        else{   // covers two cases in the second line
        // we didnt do mid -1 as the mid can be the pivot element as well and -1 would take it to the first line
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;  //RETURN START OR u could even return end.. both will be same .. this is the reasaon why while (s<e) coz everytime they both will be same
}

int main() {
    int arr[5] = {1, 3, 8, 10, 17};
    cout << "Pivot is " << getPivot(arr, 5) << endl;
}