#include<iostream>
using namespace std;


int partition( int arr[], int s, int e) {

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) { // NOTE EQUAL TO SIGN
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //to check the left and right side of pivot 
    int i = s, j = e; // Two pointer 

    while(i < pivotIndex && j > pivotIndex) {
        //  Find element such that it is greater than pivot ie shoul not be in left side and hence must be swapped
        while(arr[i] <= pivot) // NOTE = SIGN
        {
            i++;
        }
         //  Find element such that it is greater than pivot ie shoul not be in left side and hence must be swapped
        while(arr[j] > pivot) {
            j--;
        }
        // Make sure that the element to be swapped is in wrong sides before the swap
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}

void quickSort(int arr[], int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //partitioon karenfe
    int p = partition(arr, s, e);

    //left part sort karo
    quickSort(arr, s, p-1);

    //right wala part sort karo
    quickSort(arr, p+1, e);

}

int main() {

    int arr[10] = {2,4,1,6,9 ,9,9,9,9,9};
    int n = 10;

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;


    return 0;
}