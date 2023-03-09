#include<iostream> 
using namespace std;

int getPivot(int arr[], int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])  //Case when mid lies in the left hand slope ie the inclined incrementing slope /
        {
            s = mid+1;
        }
        else{ // Covers two cases ie when element is in the right hand slope decrementing inclined \ and the case when it could be the peak element aswell that is y no  mid-1 like the other prev prog.
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int main() {
    int arr[5] = {1, 3, 8, 10, 17};
    cout << "Pivot is " << getPivot(arr, 5) << endl;
}