#include <iostream>
#include <vector>
using namespace std;

// Function for merge sort
void merge(vector<double>& arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Temporary arrays
    vector<double> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge temporary arrays into main array arr[l..r]
    i = 0; // Initial index of the first subarray
    j = 0; // Initial index of the second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function for merge sort
void mergeSort(vector<double>& arr, int l, int r) {
    if (l < r) {
        // Find the middle of the array
        int m = l + (r - l) / 2;

        // Sort the first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge sorted halves
        merge(arr, l, m, r);
    }
}

int main() {
    int N;
    double firstTerm, commonRatio;

    // Enter the size of the array and the values ??of the first term and the denominator
    cout << "Enter the size of the array (100 < N < 1000): ";
    cin >> N;
    cout << "Enter the first term of the geometric progression: ";
    cin >> firstTerm;
    cout << "Enter the common ratio of the geometric progression: ";
    cin >> commonRatio;

    // Creating an array and filling it with geometric progression elements
    vector<double> arr(N);
    arr[0] = firstTerm;
    for (int i = 1; i < N; i++) {
        arr[i] = arr[i - 1] * commonRatio;
    }

    // Sorting the array by the merge method
    mergeSort(arr, 0, N - 1);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
