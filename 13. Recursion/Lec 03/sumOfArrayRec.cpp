#include<bits/stdc++.h>
using namespace std;
int Sum( int arr[], int n){
    if (n == 0)
        return 0;
    int s = arr[0]+Sum(arr+1,n-1);
    return s;
}


int main() {

    int arr[5] = {2,4,9,9,9};
    int size = 5;

    cout<<Sum(arr, size);


}