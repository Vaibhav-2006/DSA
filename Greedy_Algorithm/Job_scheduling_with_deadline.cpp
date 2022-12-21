// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include<iostream>
#include<algorithm>
using namespace std;
  
// A structure to represent a job
struct Job
{
   char id;     // Job Id
   int dead;    // Deadline of job
   int profit;  // Profit if job is over before or on deadline
};
  
// This function is used for sorting all jobs according to profit
bool comparison(Job a, Job b)
{
     return (a.profit > b.profit);
}
  
int printJobScheduling(Job arr[], int n)
{
	int profit=0;
    // Sort all jobs according to decreasing order of profit
    sort(arr, arr+n, comparison);
  	//Can be done using a single array as well in which result would be initialized with
  	// -1 to show that that slot is vacant for selection.
    int result[n]; // To store result (Sequence of jobs)
    bool slot[n];  // To keep track of free time slots
  
    // Initialize all slots to be free
    for (int i=0; i<n; i++)
        slot[i] = false;
  
    // Iterate through all given jobs
    for (int i=0; i<n; i++)
    {
       // Find a free slot for this job (Note that we start
       // from the last possible slot)
       //The min function is used so that for example if there are 7 people and the last person
       //is ready to wait till deadline 9. In this case even if all the people are provided service
       //before this 7th person still the 7th person will get service in the 7th slot and not the 9th slot.
       //Also j=9 would lie outside slot[7] and result[7] arrays.
       for (int j=min(n, arr[i].dead)-1; j>=0; j--)
       {
          // Free slot found
          if (slot[j]==false)
          {
             result[j] = i;  // Add this job to result
             slot[j] = true; // Make this slot occupied
             profit+=arr[i].profit;
             break;
          }
       }
    }
  
    // Print the result
    for (int i=0; i<n; i++)
       if (slot[i])
         cout << arr[result[i]].id << " ";
         
         return profit;
}
  
// Driver code
int main()
{
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}, {'f', 4, 50}, {'g', 2, 70}, {'h',4,55}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs \n";
    
    // Function call
    int max_profit=printJobScheduling(arr, n);
    cout << "\nFollowing is maximum profit: "<<max_profit;
    return 0;
}



