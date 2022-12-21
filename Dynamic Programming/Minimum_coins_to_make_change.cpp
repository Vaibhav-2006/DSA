// A Naive recursive C++ program to find minimum of coins
// to make a given change value
#include<bits/stdc++.h>
using namespace std;

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int value)
{
// base case
if (value == 0) return 0;

// Initialize result
int res = INT_MAX;

// Try every coin that has smaller value than value
for (int i=0; i<m; i++)
{
	if (coins[i] <= value)
	{
		int sub_res = minCoins(coins, m, value-coins[i]);

		// Check for INT_MAX to avoid overflow and see if
		// result can minimized
		if (sub_res != INT_MAX)
			res = min(res,sub_res + 1);
	}
}
return res;
}

int MinCoins(int coins[], int m, int value)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[value] will have result
    int table[value+1];
 
    // Base case (If given value value is 0)
    table[0] = 0;
 
    // Initialize all table values as Infinite
    for (int i=1; i<=value; i++)
        table[i] = INT_MAX;
 
    // Compute minimum coins required for all
    // values from 1 to value
    for (int i=1; i<=value; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<m; j++)
          if (coins[j] <= i)
          {
              int sub_res = table[i-coins[j]];
              if (sub_res != INT_MAX)
                  table[i] = min(table[i],sub_res + 1);
          }
    }
   
      if(table[value]==INT_MAX)
        return -1;
   
    return table[value];
}
 

// Driver program to test above function
int main()
{
	int coins[] = {9, 6, 5, 1};
	int m = sizeof(coins)/sizeof(coins[0]);
	int value = 11;
	cout << "Minimum coins required is "
		<< MinCoins(coins, m, value);
	return 0;
}

