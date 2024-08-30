#include<bits/stdc++.h>
using namespace std;

int main() {

    int N, c, start;
    ofstream outFile("input.txt");
    if (!outFile) {
        std::cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    cout << "Select type of Input : \n";
    cout << "Enter 1 for random generated elements\n";
    cout << "Enter 2 for elements sorted in increasing order\n";
    cout << "Enter 3 for elements sorted in decreasing order\n\n";
    cout << "Enter your choice : ";
    cin >> c;

    cout<<"\nEnter no. of Inputs : ";
    cin>>N;
    outFile << N <<endl;

    switch(c) {
        case 1: 
            for(int i=0; i<N; i++) {
                outFile << rand()%N+ 1 <<endl;
            }
            break;
        case 2:
            start = 1;
            for(int i=0; i<N; i++) {
                start += rand()%100;
                outFile << start <<endl;
            }
            break;
        case 3:
            start = N*10;
            for(int i=0; i<N; i++) {
                start -= rand()%100;
                outFile << start <<endl;
            }
            break;
        default: cout<<"Invalid choice";
    };
    

    outFile.close();

    return 0;
}