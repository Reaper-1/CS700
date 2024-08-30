#include <bits/stdc++.h>
using namespace std;


// Function to swap two elements in the array
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to partition the array around the pivot
int partition(int arr[], int low, int high) {
    // Choose the first element as the pivot
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (left <= right) {
        // Move the left index to the right while elements are less than the pivot
        while (left <= right && arr[left] <= pivot) {
            ++left;
        }
        // Move the right index to the left while elements are greater than the pivot
        while (left <= right && arr[right] > pivot) {
            --right;
        }
        // Swap elements if indices have not crossed
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
    
    // Swap the pivot element with the element at the right index
    swap(arr[low], arr[right]);

    return right; // Return the index of the pivot
}

// Recursive Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively apply Quick Sort to the subarrays
        quickSort(arr, low, pivotIndex - 1);  // Before pivot
        quickSort(arr, pivotIndex + 1, high); // After pivot
    }
}

int main()
{
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
    quickSort(arr, 0, N-1);
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by quick sort with first element as pivot is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec" <<endl << "\n\n";

    return 0;
}
  
