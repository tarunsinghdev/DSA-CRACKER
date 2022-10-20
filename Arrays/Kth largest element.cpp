#include <iostream>  

#include <bits/stdc++.h>  

using namespace std;  

  

// Function that returns the Kth largest element  

int kth_largest_element(int arr[], int k, int n){  

    // Sorts the array  

    sort(arr, arr + n);  

  

    // Reverses the array  

    reverse(arr, arr+n);  

  

    // Returns the required element  

    return arr[k-1];  

}  

  

int main(){  

    // Given array  

    int arr[] = {12, 15, 7, 3, 8, 16, 25};  

  

    // n represents the size of the array  

    int n = sizeof(arr) / sizeof(arr[0]);  

  

    int k = 3;  

    cout << "The "<< k << "th largest element = " << kth_largest_element(arr, k, n) << endl;  

    return 0;  

}  
