#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    // Calculate the sizes of the two subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays for the two subarrays
    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    // Copy data to temporary arrays
    std::copy(arr + left, arr + mid + 1, leftArray);
    std::copy(arr + mid + 1, arr + right + 1, rightArray);

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k++] = leftArray[i++];
        } else {
            arr[k++] = rightArray[j++];
        }
    }

    // Copy remaining elements of leftArray, if any
    while (i < n1) {
        arr[k++] = leftArray[i++];
    }

    // Copy remaining elements of rightArray, if any
    while (j < n2) {
        arr[k++] = rightArray[j++];
    }

    // Clean up temporary arrays
    delete[] leftArray;
    delete[] rightArray;
}

// Recursive Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {

    int N, element;
    clock_t start, end;
    ifstream inFile("input.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    inFile >> N;
    int arr[N];

    for (int i=0; i<N; i++) {
        inFile >> element;
        arr[i] = element;
    }
    cout<<"Sorting "<< N <<" elements..."<<endl;

    start = clock();
    mergeSort(arr, 0, N-1);
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by merge sort is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec" <<endl << "\n\n";

    return 0;
}