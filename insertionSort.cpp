#include <bits/stdc++.h>
using namespace std;

// Function to perform insertion sort and count comparisons
void insertionSort(int arr[], int n, int &comparisons)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Compare elements and count comparisons
        while (j >= 0 && arr[j] > key) {
            comparisons++; // Increment comparison count
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // If the loop exited due to j < 0, there was one more comparison that failed
        if (j >= 0) {
            comparisons++;
        }
        
        arr[j + 1] = key;
    }
}

int main() {
    int N, element;
    clock_t start, end;
    int comparisons = 0; // Initialize comparison counter

    ifstream inFile("input.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    inFile >> N;
    int arr[N];

    for (int i = 0; i < N; i++) {
        inFile >> element;
        arr[i] = element;
    }
    cout << "Sorting " << N << " elements..." << endl;

    start = clock();
    insertionSort(arr, N, comparisons);
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by insertion sort is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec" << endl;

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
