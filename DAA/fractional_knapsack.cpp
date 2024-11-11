#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort to sort the items based on their profit/weight ratio in descending order
void bubbleSort(vector<int>& W, vector<int>& P, vector<double>& ratio, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                // Swap ratios
                swap(ratio[j], ratio[j + 1]);
                // Swap corresponding weights
                swap(W[j], W[j + 1]);
                // Swap corresponding profits
                swap(P[j], P[j + 1]);
            }
        }
    }
}

int main() {
    int n = 3; // Number of items
    vector<int> W(n);  // Weights
    vector<int> P(n);  // Profits
    vector<double> ratio(n);  // Profit/Weight ratio
    
    double totalProfit = 0.0;
    double Capacity;  // Knapsack capacity
    
    cout<<"Enter the Knapsack Capacity"<<endl;
    cin>>Capacity;
    cout<<endl;
    // Input weights and profits of 3 items
    for (int i = 0; i < n; i++) {
        cout << "Enter Profit of item " << i + 1 << ": ";
        cin >> P[i];
        cout << "Enter Weight of item " << i + 1 << ": ";
        cin >> W[i];
    }

    // Calculate profit/weight ratio for each item
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)P[i] / W[i];
    }

    // Sort items based on profit/weight ratio in descending order
    bubbleSort(W, P, ratio, n);

    // Greedy approach to select items
    for (int i = 0; i < n; i++) {
        if (W[i] <= Capacity) {
            // If item can fully fit in the remaining capacity
            totalProfit += P[i];
            Capacity -= W[i];
        }
        else {
            // Take the fraction of the item
            totalProfit +=  P[i]* (Capacity/W[i]);
            break; // Knapsack is full, no more items can fit
        }

        // If the knapsack is full, break the loop
        if (Capacity == 0) {
            break;
        }
    }

    // Output the maximum profit
    cout << "Maximum profit: " << totalProfit << endl;

    return 0;
}

//sample input/output

// Enter Profit of item 1: 100
// Enter Weight of item 1: 20
// Enter Profit of item 2: 60
// Enter Weight of item 2: 10
// Enter Profit of item 3: 120
// Enter Weight of item 3: 30
// Maximum profit: 240
