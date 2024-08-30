#include<bits/stdc++.h>
using namespace std;

// Function to swap two elements in the array
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to find the median of the first, middle, and last elements
int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    // Compare first, middle, and last elements and find the median
    if (arr[low] > arr[mid]) {
        swap(arr[low], arr[mid]);
    }
    if (arr[low] > arr[high]) {
        swap(arr[low], arr[high]);
    }
    if (arr[mid] > arr[high]) {
        swap(arr[mid], arr[high]);
    }

    // The median is now at the middle
    return mid;
}

// Function to partition the array around the pivot
int partition(int arr[], int low, int high) {
    // Find the median of the first, middle, and last elements
    int pivotIndex = medianOfThree(arr, low, high);
    int pivot = arr[pivotIndex];

    // Move the pivot to the end of the array range
    swap(arr[pivotIndex], arr[high]);
    pivotIndex = high;

    int left = low;
    int right = high - 1;

    while (left <= right) {
        // Move the left index to the right while elements are less than or equal to pivot
        while (left <= right && arr[left] <= pivot) {
            ++left;
        }
        // Move the right index to the left while elements are greater than pivot
        while (left <= right && arr[right] > pivot) {
            --right;
        }
        // Swap elements if indices have not crossed
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }

    // Place the pivot in its correct position
    swap(arr[left], arr[pivotIndex]);

    return left; // Return the index of the pivot
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
    cout << "Time taken by quick sort with median of first middle and last element as pivot is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec" <<endl << "\n\n";  
       

    return 0;

}
