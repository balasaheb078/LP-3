#include<iostream>
#include<vector>

using namespace std;

int main() {
    int capacity, items;

    // Take the number of items and capacity as input
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    cout << "Enter the number of items: ";
    cin >> items;

    // Arrays to store prices and weights of the items
    vector<int> price(items + 1);
    vector<int> wt(items + 1);

    // Input the value and weight for each item
    for (int i = 1; i <= items; i++) {
        cout << "Enter value and weight for item " << i << ": ";
        cin >> price[i] >> wt[i];
    }

    // DP table to store the maximum profit for each subproblem
    vector<vector<int>> dp(items + 1, vector<int>(capacity + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= items; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (wt[i] <= j) {
                // If current item's weight is less than or equal to the remaining capacity
                dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j - wt[i]]);
            } else {
                // Else, we cannot include the current item
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Output the maximum profit that can be earned
    cout << "Maximum Profit Earned: " << dp[items][capacity] << "\n";

    return 0;
}

/*
0/1 Knapsack :
Time Complexity: O(N*W). 
where ‘N’ is the number of items and ‘W’ is the knapsack capacity. As for every item, we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of a 2-D array of size ‘N*W’.

Enter the capacity of the knapsack: 10
Enter the number of items: 4
Enter value and weight for item 1: 3 2
Enter value and weight for item 2: 7 2
Enter value and weight for item 3: 2 4
Enter value and weight for item 4: 9 5

*/