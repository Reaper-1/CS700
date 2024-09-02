#include <bits/stdc++.h>
using namespace std;

int comparisons; // Global variable to count comparisons

// Bubble Sort
void bubbleSort(int arr[], int n) {
    comparisons = 0; // Reset comparisons for bubble sort
    bool isUnsorted;
    do {
        isUnsorted = false;
        for (int i = 0; i < (n - 1); i++) {
            comparisons++;
            if (arr[i] > arr[i + 1]) {
                isUnsorted = true;
                swap(arr[i], arr[i + 1]);
            }
        }
    } while (isUnsorted);
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    comparisons = 0; // Reset comparisons for insertion sort
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        if (j >= 0) comparisons++;
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort (First Element as Pivot)
int partitionFirst(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

void quickSortFirst(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionFirst(arr, low, high);
        quickSortFirst(arr, low, pi - 1);
        quickSortFirst(arr, pi + 1, high);
    }
}

// Quick Sort (Random Element as Pivot)
int partitionRandom(int arr[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[low]);
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

void quickSortRandom(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionRandom(arr, low, high);
        quickSortRandom(arr, low, pi - 1);
        quickSortRandom(arr, pi + 1, high);
    }
}

// Quick Sort (Median of First, Middle, and Last Element as Pivot)
int partitionMedian(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    int a = arr[low], b = arr[mid], c = arr[high];
    int pivot = (a < b) ? ((b < c) ? b : (a < c) ? c : a) : ((b < c) ? c : (a < c) ? a : b);
    int pivotIndex = (arr[low] == pivot) ? low : ((arr[mid] == pivot) ? mid : high);
    swap(arr[pivotIndex], arr[low]);
    int pivotVal = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        comparisons++;
        if (arr[j] < pivotVal) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

void quickSortMedian(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionMedian(arr, low, high);
        quickSortMedian(arr, low, pi - 1);
        quickSortMedian(arr, pi + 1, high);
    }
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    comparisons++;
    if (l < n && arr[l] > arr[largest]) largest = l;

    comparisons++;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    comparisons = 0; // Reset comparisons for heap sort
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Radix Sort
void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++) count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    comparisons = 0; // Reset comparisons for radix sort
    int maxVal = *max_element(arr, arr + n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) countSort(arr, n, exp);
}

// Function to generate arrays in different orders
void generateArrays(int arr[], int n, string type) {
    if (type == "random") {
        for (int i = 0; i < n; i++) arr[i] = rand() % 10000; // Random values
    } else if (type == "increasing") {
        for (int i = 0; i < n; i++) arr[i] = i; // Increasing order
    } else if (type == "decreasing") {
        for (int i = 0; i < n; i++) arr[i] = n - i; // Decreasing order
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    int N = 40000; // Adjust size as needed

    // Arrays for testing
    int arr1[N], arr2[N], arr3[N], arr4[N], arr5[N], arr6[N];

    vector<string> types = {"random", "increasing", "decreasing"};

    for (const string& type : types) {
        generateArrays(arr1, N, type);

        // Bubble Sort
        int arrBubble[N];
        copy(arr1, arr1 + N, arrBubble);
        clock_t start = clock();
        bubbleSort(arrBubble, N);
        clock_t end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Bubble Sort (" << type << "): " << fixed << time_taken << setprecision(5) << " sec, Comparisons: " << comparisons << endl;

        // Insertion Sort
        int arrInsertion[N];
        copy(arr1, arr1 + N, arrInsertion);
        start = clock();
        insertionSort(arrInsertion, N);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Insertion Sort (" << type << "): " << fixed << time_taken << setprecision(5) << " sec, Comparisons: " << comparisons << endl;

        // Merge Sort
        int arrMerge[N];
        copy(arr1, arr1 + N, arrMerge);
        comparisons = 0; // Reset comparisons for merge sort
        start = clock();
        mergeSort(arrMerge, 0, N - 1);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Merge Sort (" << type << "): " << fixed << time_taken << setprecision(5) << " sec, Comparisons: " << comparisons << endl;

        // Quick Sort (First Element as Pivot)
        int arrQuickFirst[N];
        copy(arr1, arr1 + N, arrQuickFirst);
        comparisons = 0; // Reset comparisons for quick sort (first element)
        start = clock();
        quickSortFirst(arrQuickFirst, 0, N - 1);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Quick Sort (First Element) (" << type << "): " << fixed << time_taken << setprecision(5) << " sec, Comparisons: " << comparisons << endl;

        // Quick Sort (Random Element as Pivot)
        int arrQuickRandom[N];
        copy(arr1, arr1 + N, arrQuickRandom);
        comparisons = 0; // Reset comparisons for quick sort (random element)
        start = clock();
        quickSortRandom(arrQuickRandom, 0, N - 1);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Quick Sort (Random Element) (" << type << "): " << fixed << time_taken << setprecision(5) << " sec, Comparisons: " << comparisons << endl;

        // Quick Sort (Median of Three as Pivot)
        int arrQuickMedian[N];
        copy(arr1, arr1 + N, arrQuickMedian);
        comparisons = 0; // Reset comparisons for quick sort (median of three)
        start = clock();
        quickSortMedian(arrQuickMedian, 0, N - 1);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Quick Sort (Median of Three) (" << type << "): " << fixed << time_taken << setprecision(5) << " sec, Comparisons: " << comparisons << endl;

        // Heap Sort
        int arrHeap[N];
        copy(arr1, arr1 + N, arrHeap);
        comparisons = 0; // Reset comparisons for heap sort
        start = clock();
        heapSort(arrHeap, N);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Heap Sort (" << type << "): " << fixed << time_taken << setprecision(5) << " sec, Comparisons: " << comparisons << endl;

        // Radix Sort
        int arrRadix[N];
        copy(arr1, arr1 + N, arrRadix);
        start = clock();
        radixSort(arrRadix, N);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Radix Sort (" << type << "): " << fixed << time_taken << setprecision(5) << " sec" << endl;

        cout << "---------------------------------------------------" << endl;
    }

    return 0;
}
