#include<iostream>
using namespace std;

void merge(int *arr, int s, int e) {

    int mid = (s+e)/2;

// Length of 1st element from start to mid, calculated using mid - start +1
    int len1 = mid - s + 1;
// Length of 1st element from mid to end, calculated using end - mid 
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values 

    // For the first array start from first index
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    // For the second array start from mid+1
    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}

void mergeSort(int *arr, int s, int e) {

    //base case
    // NOTE : HAVING EQUAL TO SIGN IS MUST, otherwise unlimted loop, if the start and end at the same ele, means sorted
    if(s >= e) {
        return;
    }
    
    int mid = (s+e)/2;

    //sort the left part
    mergeSort(arr, s, mid);
    
    //sort the right part
    mergeSort(arr, mid+1, e);

    //merge
    merge(arr, s, e);

}

int main() {

    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    mergeSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}