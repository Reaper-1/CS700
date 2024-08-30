#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    bool isUnsorted;
    do
    {
        isUnsorted = false;
        for (int i = 0; i < (n - 1); i++)
        {
            if (arr[i] > arr[i + 1])
            {
                isUnsorted = true;
                for (; i < (n - 1); i++)
                {
                    if (arr[i] > arr[i + 1])
                    {
                        std::swap(arr[i], arr[i + 1]);
                    }
                }
            }
        }
    } while (isUnsorted);
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
    bubbleSort(arr, N);
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by bubble sort is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec" <<endl << "\n\n"; 

    // ofstream outfile("output.txt");
    // if (!outfile) {
    //     cerr << "Error opening file for reading!" << endl;
    //     return 1;
    // }
    // for (int i=0; i<N; i++) {
    //     element = arr[i];
    //     outfile << element <<endl;       
    // }
    // outfile.close();

    return 0;
}