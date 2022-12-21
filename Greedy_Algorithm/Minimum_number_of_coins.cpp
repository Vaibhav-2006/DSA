// C++ program to find minimum
// number of denominations
#include <bits/stdc++.h>
using namespace std;
  
// All denominations of Indian Currency
int denomination[] = { 1, 2, 10, 5, 20,
               50, 100, 500, 1000 };
int n = sizeof(denomination) / sizeof(denomination[0]);
  
void findMin(int V)
{
    sort(denomination, denomination + n);//ascending order
  
    // Initialize result
    vector<int> ans;
  
    // Traverse through all denominationmination
    for (int i = n - 1; i >= 0; i--) {
  
        // Find denominationminations
        while (V >= denomination[i]) {
            V -= denomination[i];//500 2
            ans.push_back(denomination[i]);
        }
    }
  
    // Print result
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}
  
// Driver program
int main()
{
    int n = 93;
    cout << "Following is minimal"
         << " number of change for " << n
         << ": ";
    findMin(n);
    return 0;
}
//Some notes from gfg
//Complexity Analysis: 
//Worst case is when the denominations array contains only 1.
//Time Complexity: O(V).
//Auxiliary Space: O(V).
//In spite of nested loops complexity is O(N).
//Note: The above approach may not work for all denominations. For example, 
//it doesn't work for denominations {9, 6, 5, 1} and V = 11. The above approach 
//would print 9, 1 and 1. But we can use 2 denominations 5 and 6. 
//For general input, use dynamic programming approach. 
