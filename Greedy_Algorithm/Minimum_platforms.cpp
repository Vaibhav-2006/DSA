// Program to find minimum number of platforms
// required on a railway station
#include <algorithm>
#include <iostream>

using namespace std;

struct Train{
int arr;
int dept;
Train(int arr, int dept)
{
	this->arr=arr;
	this->dept=dept;
}	
};

bool cmp(Train t1, Train t2)
{
	return t1.arr<t2.arr;
}
// Returns minimum number of platforms required
int findPlatform(Train train[], int n)
{
	// Sort Trains based on their arrival time
	sort(train,train+n,cmp);
	// plat_needed indicates number of platforms
	// needed at a time
	int plat_needed = 1, result = 1;
	int i = 0, j = 1;

	while (i < n && j < n) {
		
		if (train[i].dept < train[j].arr) {
			i++;
			j=i+1;
			plat_needed=1;
		}

		// Else decrement count of platforms needed
		else if (train[i].dept >= train[j].arr) {
			plat_needed++;
			j++;
		}

		// Update result if needed
		if (plat_needed > result)
			result = plat_needed;
	}
	return result;
}

// Driver code
int main()
{
	Train train[]={{900,910},{940,1200},{950,1120},{1100,1130},{1500,1900},{1800,2000}};
	int n = sizeof(train) / sizeof(train[0]);
	cout << "Minimum Number of Platforms Required = "
		<< findPlatform(train, n);
	return 0;
}
