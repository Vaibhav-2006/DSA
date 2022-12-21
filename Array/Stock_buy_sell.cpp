// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
//Naive approach
// Function to return the maximum profit
// that can be made after buying and
// selling the given stocks
int maxProfit(int price[], int start, int end)
{

	// If the stocks can't be bought
	if (end <= start)
		return 0;

	// Initialise the profit
	int profit = 0;

	// The day at which the stock
	// must be bought
	for (int i = start; i < end; i++) {

		// The day at which the
		// stock must be sold
		for (int j = i + 1; j <= end; j++) {

			// If buying the stock at ith day and
			// selling it at jth day is profitable
			if (price[j] > price[i]) {

				// Update the current profit
				int curr_profit = price[j] - price[i]
								+ maxProfit(price, start, i - 1)
								+ maxProfit(price, j + 1, end);

				// Update the maximum profit so far
				profit = max(profit, curr_profit);
			}
		}
	}
	return profit;
}


// Efficient approach in O(n) time

int max_Profit(int* prices, int size)
{
    // maxProfit adds up the difference between
    // adjacent elements if they are in increasing order
    int maxProfit = 0;
    // The loop starts from 1
    // as its comparing with the previous
    for(int i=1;i<size;i++) 
		if (prices[i] > prices[i - 1])
        	maxProfit+= prices[i] - prices[i - 1];
    return maxProfit;
}

// Driver code
int main()
{
	int price[] = { 100, 180, 260, 310,
					40, 535, 695 };
	int n = sizeof(price) / sizeof(price[0]);

	cout << max_Profit(price, n);

	return 0;
}


